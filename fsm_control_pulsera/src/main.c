#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "boards.h"
#include "nrf_delay.h"
#include "nrf_pwr_mgmt.h"

#include "fsm_control_pulsera.h"
#include "fsm.h"
#include "adc.h"

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
    bsp_board_init(BSP_INIT_BUTTONS|BSP_INIT_LEDS);

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
