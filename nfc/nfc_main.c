#include <stdint.h>
#include "nfc_t2t_lib.h"
#include "nfc_ndef_msg.h"
#include "nfc_text_rec.h"
#include "boards.h"
#include "app_error.h"
#include "hardfault.h"


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#define MAX_REC_COUNT      1     /**< Maximum records count. */

    /** @snippet [NFC text usage_1] */
static const uint8_t payload[] =
{
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};
    /** @snippet [NFC text usage_1] */
   
/* Buffer used to hold an NFC NDEF message. */
uint8_t m_ndef_msg_buf[256];

/**
 * @brief Callback function for handling NFC events.
 */
static void nfc_callback(void * p_context, nfc_t2t_event_t event, const uint8_t * p_data, size_t data_length)
{
    (void)p_context;

    switch (event)
    {
        case NFC_T2T_EVENT_FIELD_ON:
            bsp_board_led_on(BSP_BOARD_LED_0);
            break;
        case NFC_T2T_EVENT_FIELD_OFF:
            bsp_board_led_off(BSP_BOARD_LED_0);
            break;
        default:
            break;
    }
}


/**
 * @brief Function for encoding the NDEF text message.
 */
static ret_code_t msg_encode(uint8_t * p_buffer, uint32_t * p_len)
{
    /** @snippet [NFC text usage_2] */
    ret_code_t err_code;

    /* Create NFC NDEF text record description*/
    NFC_NDEF_TEXT_RECORD_DESC_DEF(nfc_text_rec,
                                  UTF_8,
                                  en_code,
                                  sizeof(en_code),
                                  payload,
                                  sizeof(payload));
    /** @snippet [NFC text usage_2] */

    /* Create NFC NDEF message description, capacity - MAX_REC_COUNT records */
    /** @snippet [NFC text usage_3] */
    NFC_NDEF_MSG_DEF(nfc_text_msg, MAX_REC_COUNT);
    /** @snippet [NFC text usage_3] */

    /* Add text records to NDEF text message */
    /** @snippet [NFC text usage_4] */
    err_code = nfc_ndef_msg_record_add(&NFC_NDEF_MSG(nfc_text_msg),
                                       &NFC_NDEF_TEXT_RECORD_DESC(nfc_text_rec));
    VERIFY_SUCCESS(err_code);

    /** @snippet [NFC text usage_5] */
    err_code = nfc_ndef_msg_encode(&NFC_NDEF_MSG(nfc_text_msg),
                                   p_buffer,
                                   p_len);
    return err_code;
    /** @snippet [NFC text usage_5] */
}

/**
 *@brief Function for initializing logging.
 */
static void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    uint32_t  len = sizeof(m_ndef_msg_buf);
    uint32_t  err_code;

    log_init();

    /* Configure LED-pins as outputs */
    bsp_board_init(BSP_INIT_LEDS);

    /* Set up NFC */
    err_code = nfc_t2t_setup(nfc_callback, NULL);
    APP_ERROR_CHECK(err_code);

    /* Encode message */
    err_code = msg_encode(m_ndef_msg_buf, &len);
    APP_ERROR_CHECK(err_code);

    /* Set created message as the NFC payload */
    err_code = nfc_t2t_payload_set(m_ndef_msg_buf, len);
    APP_ERROR_CHECK(err_code);

    /* Start sensing NFC field */
    err_code = nfc_t2t_emulation_start();
    APP_ERROR_CHECK(err_code);

    while (1)
    {
        NRF_LOG_FLUSH();
        __WFE();
    }
}
