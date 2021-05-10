#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif // HAVE_CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

#include <nfc/nfc.h>

#include "nfc-utils.h"
#include "mifare.h"

#define MAX_TARGET_COUNT 16
#define MAX_UID_LEN 10

#define EV1_NONE    0
#define EV1_UL11    1
#define EV1_UL21    2

#define NTAG_NONE 0
#define NTAG_213  1
#define NTAG_215  2
#define NTAG_216  3

static nfc_device *pnd;
static nfc_target nt;
static mifare_param mp;
static maxtag mtDump; // use the largest tag type for internal storage
static uint32_t uiBlocks = 0x10;
static uint32_t uiReadPages = 0;
static uint8_t iPWD[4] = { 0x0 };
static uint8_t iPACK[2] = { 0x0 };
static uint8_t iEV1Type = EV1_NONE;
static uint8_t iNTAGType = NTAG_NONE;

// special unlock command
uint8_t  abtUnlock1[1] = { 0x40 };
uint8_t  abtUnlock2[1] = { 0x43 };

// EV1 commands
uint8_t  abtEV1[3] = { 0x60, 0x00, 0x00 };
uint8_t  abtPWAuth[7] = { 0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

//Halt command
uint8_t  abtHalt[4] = { 0x50, 0x00, 0x00, 0x00 };

#define MAX_FRAME_LEN 264

static uint8_t abtRx[MAX_FRAME_LEN];
static int szRx;

static const nfc_modulation nmMifare = {
  .nmt = NMT_ISO14443A,
  .nbr = NBR_106,
};

static void
print_success_or_failure(bool bFailure, uint32_t *uiOkCounter, uint32_t *uiFailedCounter)
{
  printf("%c", (bFailure) ? 'f' : '.');
  if (uiOkCounter)
    *uiOkCounter += (bFailure) ? 0 : 1;
  if (uiFailedCounter)
    *uiFailedCounter += (bFailure) ? 1 : 0;
}

static  bool
read_card(void)
{
  uint32_t page;
  bool    bFailure = false;
  uint32_t uiFailedPages = 0;

  printf("Reading %d pages |", uiBlocks);

  for (page = 0; page < uiBlocks; page += 4) {
    // Try to read out the data block
    if (nfc_initiator_mifare_cmd(pnd, MC_READ, page, &mp)) {
      memcpy(mtDump.ul[page / 4].mbd.abtData, mp.mpd.abtData, uiBlocks - page < 4 ? (uiBlocks - page) * 4 : 16);
    } else {
      bFailure = true;
    }
    for (uint8_t i = 0; i < (uiBlocks - page < 4 ? uiBlocks - page : 4); i++) {
      print_success_or_failure(bFailure, &uiReadPages, &uiFailedPages);
    }
  }
  printf("|\n");
  printf("Done, %d of %d pages read (%d pages failed).\n", uiReadPages, uiBlocks, uiFailedPages);
  fflush(stdout);

  // copy EV1 secrets to dump data
  switch (iEV1Type) {
    case EV1_UL11:
      memcpy(mtDump.ul[4].mbc11.pwd, iPWD, 4);
      memcpy(mtDump.ul[4].mbc11.pack, iPACK, 2);
      break;
    case EV1_UL21:
      memcpy(mtDump.ul[9].mbc21a.pwd, iPWD, 4);
      memcpy(mtDump.ul[9].mbc21b.pack, iPACK, 2);
      break;
    case EV1_NONE:
    default:
      break;
  }
  // copy NTAG secrets to dump data
  switch (iNTAGType) {
    case NTAG_213:
      memcpy(mtDump.nt[43].mbc21356d.pwd, iPWD, 4);
      memcpy(mtDump.nt[44].mbc21356e.pack, iPACK, 2);
      break;
    case NTAG_215:
      memcpy(mtDump.nt[133].mbc21356d.pwd, iPWD, 4);
      memcpy(mtDump.nt[134].mbc21356e.pack, iPACK, 2);
      break;
    case NTAG_216:
      memcpy(mtDump.nt[229].mbc21356d.pwd, iPWD, 4);
      memcpy(mtDump.nt[230].mbc21356e.pack, iPACK, 2);
      break;
    case NTAG_NONE:
    default:
      break;
  }

  return (!bFailure);
}

static  bool
transmit_bytes(const uint8_t *pbtTx, const size_t szTx)
{
  if ((szRx = nfc_initiator_transceive_bytes(pnd, pbtTx, szTx, abtRx, sizeof(abtRx), 0)) < 0)
    return false;

  return true;
}

static bool
raw_mode_start(void)
{
  // Configure the CRC
  if (nfc_device_set_property_bool(pnd, NP_HANDLE_CRC, false) < 0) {
    nfc_perror(pnd, "nfc_configure");
    return false;
  }
  // Use raw send/receive methods
  if (nfc_device_set_property_bool(pnd, NP_EASY_FRAMING, false) < 0) {
    nfc_perror(pnd, "nfc_configure");
    return false;
  }
  return true;
}

static bool
raw_mode_end(void)
{
  // reset reader
  // Configure the CRC
  if (nfc_device_set_property_bool(pnd, NP_HANDLE_CRC, true) < 0) {
    nfc_perror(pnd, "nfc_device_set_property_bool");
    return false;
  }
  // Switch off raw send/receive methods
  if (nfc_device_set_property_bool(pnd, NP_EASY_FRAMING, true) < 0) {
    nfc_perror(pnd, "nfc_device_set_property_bool");
    return false;
  }
  return true;
}

static bool
get_ev1_version(void)
{
  if (!raw_mode_start())
    return false;
  iso14443a_crc_append(abtEV1, 1);
  if (!transmit_bytes(abtEV1, 3)) {
    raw_mode_end();
    return false;
  }
  if (!raw_mode_end())
    return false;
  if (!szRx)
    return false;
  return true;
}

static int list_passive_targets(nfc_device *_pnd)
{
  int res = 0;

  nfc_target ant[MAX_TARGET_COUNT];

  if (nfc_initiator_init(_pnd) < 0) {
    return -EXIT_FAILURE;
  }

  if ((res = nfc_initiator_list_passive_targets(_pnd, nmMifare, ant, MAX_TARGET_COUNT)) >= 0) {
    int i;

    if (res > 0)
      printf("%d ISO14443A passive target(s) found:\n", res);

    for (i = 0; i < res; i++) {
      size_t  szPos;

      printf("\t");
      for (szPos = 0; szPos < ant[i].nti.nai.szUidLen; szPos++) {
        printf("%02x", ant[i].nti.nai.abtUid[szPos]);
      }
      printf("\n");
    }

  }

  return 0;
}

int
main(void)
{
  uint8_t iUID[MAX_UID_LEN] = { 0x0 };
  size_t  szUID = 0;

  DBG("\nChecking arguments and settings\n");
  // Get commandline options
  nfc_context *context;
  nfc_init(&context);
  if (context == NULL) {
    ERR("Unable to init libnfc (malloc)");
    exit(EXIT_FAILURE);
  }

  // Try to open the NFC device
  pnd = nfc_open(context, NULL);
  if (pnd == NULL) {
    ERR("Error opening NFC device");
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }
  printf("NFC device: %s opened\n", nfc_device_get_name(pnd));

  if (list_passive_targets(pnd)) {
    nfc_perror(pnd, "nfc_device_set_property_bool");
    nfc_close(pnd);
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }

  if (nfc_initiator_init(pnd) < 0) {
    nfc_perror(pnd, "nfc_initiator_init");
    nfc_close(pnd);
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }

  // Let the device only try once to find a tag
  if (nfc_device_set_property_bool(pnd, NP_INFINITE_SELECT, false) < 0) {
    nfc_perror(pnd, "nfc_device_set_property_bool");
    nfc_close(pnd);
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }

  // Try to find a MIFARE Ultralight tag
  if (nfc_initiator_select_passive_target(pnd, nmMifare, (szUID) ? iUID : NULL, szUID, &nt) <= 0) {
    ERR("no tag was found\n");
    nfc_close(pnd);
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }

  // Test if we are dealing with a MIFARE compatible tag
  if (nt.nti.nai.abtAtqa[1] != 0x44) {
    ERR("tag is not a MIFARE Ultralight card\n");
    nfc_close(pnd);
    nfc_exit(context);
    exit(EXIT_FAILURE);
  }
  // Get the info from the current tag
  printf("Using MIFARE Ultralight card with UID: ");
  size_t  szPos;
  for (szPos = 0; szPos < nt.nti.nai.szUidLen; szPos++) {
    printf("%02x", nt.nti.nai.abtUid[szPos]);
  }
  printf("\n");

  // test if tag is EV1 or NTAG
  if (get_ev1_version()) {
    if (abtRx[6] == 0x0b || abtRx[6] == 0x00) {
      printf("EV1 type: MF0UL11 (48 bytes)\n");
      uiBlocks = 20; // total number of 4 byte 'pages'
      iEV1Type = EV1_UL11;
    } else if (abtRx[6] == 0x0e) {
      printf("EV1 type: MF0UL21 (128 user bytes)\n");
      uiBlocks = 41;
      iEV1Type = EV1_UL21;
    } else if (abtRx[6] == 0x0f) {
      printf("NTAG Type: NTAG213 (144 user bytes)\n");
      uiBlocks = 45;
      iNTAGType = NTAG_213;
    } else if (abtRx[6] == 0x11) {
      printf("NTAG Type: NTAG215 (504 user bytes)\n");
      uiBlocks = 135;
      iNTAGType = NTAG_215;
    } else if (abtRx[6] == 0x13) {
      printf("NTAG Type: NTAG216 (888 user bytes)\n");
      uiBlocks = 231;
      iNTAGType = NTAG_216;
    } else {
      printf("unknown! (0x%02x)\n", abtRx[6]);
      exit(EXIT_FAILURE);
    }
  } else {
    // re-init non EV1 tag
    if (nfc_initiator_select_passive_target(pnd, nmMifare, (szUID) ? iUID : NULL, szUID, &nt) <= 0) {
      ERR("no tag was found\n");
      nfc_close(pnd);
      nfc_exit(context);
      exit(EXIT_FAILURE);
    }
  }
    memset(&mtDump, 0x00, sizeof(mtDump));
    bool bRF = read_card();
    printf("Writing data \n");
    char *id =((char*)(&mtDump))+26;
    char id_final[13];
    strncpy(id_final,id,strlen(id)-1);
    printf("id:%s \n", id_final);
if (!bRF) {
      printf("Warning! Read failed - partial data written to file!\n");
    }  
  nfc_close(pnd);
  nfc_exit(context);
  exit(EXIT_SUCCESS);
}
