#ifndef NFC_H
#define NFC_H

#define MAX_REC_COUNT      1     /**< Maximum records count. */

    /** @snippet [NFC text usage_1] */
static const uint8_t payload[] = "Hola Mundo";

static const uint8_t id_code[] = "id";
    /** @snippet [NFC text usage_1] */

/* Buffer used to hold an NFC NDEF message. */
uint8_t m_ndef_msg_buf[256];


void nfc_callback(void * p_context, nfc_t2t_event_t event, const uint8_t * p_data, size_t data_length);

ret_code_t msg_encode(uint8_t * p_buffer, uint32_t * p_len);

#endif
