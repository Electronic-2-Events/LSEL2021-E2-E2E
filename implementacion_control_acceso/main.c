#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"

#include "fsm.h"
#include "fsm_control_entrada.h"

int button_activation(){
  return bsp_board_button_state_get(BSP_BOARD_BUTTON_0);
}

int sensor_prox(){
  return bsp_board_button_state_get(BSP_BOARD_BUTTON_1);
}

int timer_activation(){
  return deadline;
}


int main(void)
{
    //Configure all leds and buttons on board.
    bsp_board_init(BSP_INIT_BUTTONS|BSP_INIT_LEDS);
    init_timer();

//fsm
    fsm_control_entrada_t f;
    fsm_control_entrada_init(&f,button_activation,timer_activation,sensor_prox,timer_activation);

    while (1)
    {
    fsm_fire((fsm_t *)(&f));
        //__WFI();
    }
}

/** @} */
