#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "boards.h"
#include "nrf_delay.h"
#include "nrf_pwr_mgmt.h"

#include "nfc_t2t_lib.h"
#include "nfc.h"

#include "fsm_control_pulsera.h"
#include "fsm.h"
#include "adc.h"

extern uint8_t m_ndef_msg_buf[256];
extern uint16_t ldrvalue;

int nfc_activation(){
  return bsp_board_button_state_get(BSP_BOARD_BUTTON_0);
}

int ldr_deactivation(){
  return ldrvalue>300;
}

int main(void)
{
    fsm_control_pulsera_t f;
    fsm_control_pulsera_init(&f,NULL,nfc_activation,ldr_deactivation);

    saadc_init();
    saadc_sampling_event_init();
    saadc_sampling_event_enable();
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
        fsm_fire((fsm_t *)(&f));
    
        if (f.fsm.current_state==SUSPENDED){
            bsp_board_led_invert(BSP_BOARD_LED_0);
        }
                if (f.fsm.current_state==IDLE){
            bsp_board_led_invert(BSP_BOARD_LED_1);
        }
        nrf_pwr_mgmt_run();
        nrf_delay_ms(500);

    }
}


/** @} */
