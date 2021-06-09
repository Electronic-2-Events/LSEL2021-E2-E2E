/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr.h>
#include <power/reboot.h>

#include <nfc_t2t_lib.h>
#include <nfc/ndef/msg.h>
#include <nfc/ndef/text_rec.h>

#include <dk_buttons_and_leds.h>

#define MAX_REC_COUNT		3
#define NDEF_MSG_BUF_SIZE	128

#define NFC_FIELD_LED		DK_LED1

int button = 0;

/* Text message in English with its language code. */
static const uint8_t active_payload[8] = {
	"12345678"
};

static const uint8_t name_on[] = {
	"Anna Martinez"
};
static const uint8_t name_off[] = {
	"NONAME"
};

static const uint8_t dni_on[] = {
	"12345678F"
};

static const uint8_t dni_off[] = {
	"NODNI     "
};

static uint8_t id_payload[8]; 

static const uint8_t id_code[] = {'i', 'd'};

/* Text message in Norwegian with its language code. */

static uint8_t name_payload[64];

static const uint8_t name_code[] = {"name"};

static uint8_t dni_payload[9];

static const uint8_t dni_code[] = {"dni"};



/* Buffer used to hold an NFC NDEF message. */
static uint8_t ndef_msg_buf[NDEF_MSG_BUF_SIZE];


static void nfc_callback(void *context,
			 enum nfc_t2t_event event,
			 const uint8_t *data,
			 size_t data_length)
{
	ARG_UNUSED(context);
	ARG_UNUSED(data);
	ARG_UNUSED(data_length);

	switch (event) {
	case NFC_T2T_EVENT_FIELD_ON:
		dk_set_led_on(NFC_FIELD_LED);
		break;
	case NFC_T2T_EVENT_FIELD_OFF:
		dk_set_led_off(NFC_FIELD_LED);
		break;
	default:
		break;
	}
}


/**
 * @brief Function for encoding the NDEF text message.
 */
static int msg_encode(uint8_t *buffer, uint32_t *len)
{
	int err;

	/* Create NFC NDEF text record description id */
	NFC_NDEF_TEXT_RECORD_DESC_DEF(nfc_id_text_rec,
				      UTF_8,
				      id_code,
				      sizeof(id_code),
				      id_payload,
				      sizeof(id_payload));

	/* Create NFC NDEF text record description name */
	NFC_NDEF_TEXT_RECORD_DESC_DEF(nfc_name_text_rec,
				      UTF_8,
				      name_code,
				      sizeof(name_code),
				      name_payload,
				      sizeof(name_payload));

       /* Create NFC NDEF text record description dni */
	NFC_NDEF_TEXT_RECORD_DESC_DEF(nfc_dni_text_rec,
				      UTF_8,
				      dni_code,
				      sizeof(dni_code),
				      dni_payload,
				      sizeof(dni_payload));

	/* Create NFC NDEF message description, capacity - MAX_REC_COUNT
	 * records
	 */
	NFC_NDEF_MSG_DEF(nfc_text_msg, MAX_REC_COUNT);

	/* Add text records to NDEF text message */
	err = nfc_ndef_msg_record_add(&NFC_NDEF_MSG(nfc_text_msg),
				   &NFC_NDEF_TEXT_RECORD_DESC(nfc_id_text_rec));
	if (err < 0) {
		printk("Cannot add first record!\n");
		return err;
	}
	err = nfc_ndef_msg_record_add(&NFC_NDEF_MSG(nfc_text_msg),
				   &NFC_NDEF_TEXT_RECORD_DESC(nfc_name_text_rec));
	if (err < 0) {
		printk("Cannot add second record!\n");
		return err;
	}
	err = nfc_ndef_msg_record_add(&NFC_NDEF_MSG(nfc_text_msg),
				   &NFC_NDEF_TEXT_RECORD_DESC(nfc_dni_text_rec));
	if (err < 0) {
		printk("Cannot add third record!\n");
		return err;
	}

	err = nfc_ndef_msg_encode(&NFC_NDEF_MSG(nfc_text_msg),
				      buffer,
				      len);
	if (err < 0) {
		printk("Cannot encode message!\n");
	}

	return err;
}

void button_handler(uint32_t button_state, uint32_t has_changed){
  if(button_state==1 && button==0){
    button=1;
    }
}

void messages_on(){
        int i;
for(i = 0; i< sizeof(id_payload);i++){
                id_payload[i] = active_payload[i];
              }
              for(i = 0; i< sizeof(dni_payload);i++){
                dni_payload[i] = dni_on[i];
              }
              for(i = 0; i< sizeof(name_on);i++){
                name_payload[i] = name_on[i];
              }

}

void messages_off(){
        int i;
   for(i = 0; i< sizeof(id_payload);i++){
     id_payload[i] = 48;
    }
               for(i = 0; i< sizeof(dni_payload);i++){
                dni_payload[i] = dni_off[i];
              }
              for(i = 0; i< sizeof(name_off);i++){
                name_payload[i] = name_off[i];
              }
              for(i = sizeof(name_off); i< sizeof(name_payload);i++){
                name_payload[i] = 0;
              }
}


int main(void)
{
	uint32_t len = sizeof(ndef_msg_buf);
        int c=0;
        
        messages_on();
         
        dk_buttons_init(button_handler);

	printk("Starting NFC Text Record example\n");

	/* Configure LED-pins as outputs */
	if (dk_leds_init() < 0) {
		printk("Cannot init LEDs!\n");
		goto fail;
	}

	/* Set up NFC */
	if (nfc_t2t_setup(nfc_callback, NULL) < 0) {
		printk("Cannot setup NFC T2T library!\n");
		goto fail;
	}


	/* Encode welcome message */
	if (msg_encode(ndef_msg_buf, &len) < 0) {
		printk("Cannot encode message!\n");
		goto fail;
	}


	/* Set created message as the NFC payload */
	if (nfc_t2t_payload_set(ndef_msg_buf, len) < 0) {
		printk("Cannot set payload!\n");
		goto fail;
	}


	/* Start sensing NFC field */
	if (nfc_t2t_emulation_start() < 0) {
		printk("Cannot start emulation!\n");
		goto fail;
	}
	printk("NFC configuration done\n");

        while(1){
          if(button==1){
            button = 0;
            c++;
            if(c%2==0){
              messages_on();
            }
            else{
              messages_off();
            }
            	/* Encode welcome message */
            if (msg_encode(ndef_msg_buf, &len) < 0) {
		printk("Cannot encode message!\n");
            goto fail;
	}

          }
          __WFE();
        }

	return 0;

fail:
#if CONFIG_REBOOT
	sys_reboot(SYS_REBOOT_COLD);
#endif /* CONFIG_REBOOT */

	return -EIO;
}

