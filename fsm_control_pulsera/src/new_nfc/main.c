#include <stdint.h>
#include "nfc_t2t_lib.h"
#include "nfc_ndef_msg.h"
#include "nfc_text_rec.h"
#include "boards.h"

#include "nfc.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    uint32_t  len = sizeof(m_ndef_msg_buf);
    uint32_t  err_code;

    /* Configure LED-pins as outputs */
    bsp_board_init(BSP_INIT_LEDS);

    /* Set up NFC */
    err_code = nfc_t2t_setup(nfc_callback, NULL);

    /* Encode message */
    err_code = msg_encode(m_ndef_msg_buf, &len);

    /* Set created message as the NFC payload */
    err_code = nfc_t2t_payload_set(m_ndef_msg_buf, len);

    /* Start sensing NFC field */
    err_code = nfc_t2t_emulation_start();

    while (1)
    {
        __WFE();
    }
}