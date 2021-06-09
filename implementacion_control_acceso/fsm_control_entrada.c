#include <stddef.h>

#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#define DEADLINE10 (10)
#define DEADLINE3 (3)

const nrf_drv_timer_t TIMER_LED = NRF_DRV_TIMER_INSTANCE(0);
int deadline=0;

//ENTRADAS
static int fsm_NFC(fsm_t *f)
{
    fsm_control_entrada_t* fp = (fsm_control_entrada_t*)f;

    if (fp->NFC){
        return fp->NFC();
    }
    return 0;
}

static int fsm_s_bar_top(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;

    if (fp->s_bar_top)
    {
        return fp->s_bar_top();
    }
    return 0;
}

static int fsm_timer_timeout(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;

    if (fp->s_bar_top)
    {
        return fp->s_bar_top();
    }
    return 0;
}

static int fsm_s_prox(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;

    if (fp->s_prox)
    {
        return fp->s_prox();
    }
    return 0;
}

static int fsm_s_bar_bottom(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;

    if (fp->s_bar_bottom)
    {
        return fp->s_bar_bottom();
    }
    return 0;
}

//SALIDAS
void timer_event_handler(nrf_timer_event_t event_type, void* p_context)
{
    switch (event_type)
    {
        case NRF_TIMER_EVENT_COMPARE0:
            deadline=1;
            nrf_drv_timer_disable(&TIMER_LED);
            break;

        default:
            //Do nothing.
            break;
    }
}
void init_timer(int delay)
{ 
    uint32_t err_code = NRF_SUCCESS;
    //Configure TIMER_LED for generating simple light effect - leds on board will invert his state one after the other.
    nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
    err_code = nrf_drv_timer_init(&TIMER_LED, &timer_cfg, timer_event_handler);
    APP_ERROR_CHECK(err_code);

};


void timer(int delay)
{
  uint32_t time_ms = delay; //Time(in miliseconds) between consecutive compare events.
    nrf_drv_timer_enable(&TIMER_LED);
 uint32_t time_ticks = nrf_drv_timer_ms_to_ticks(&TIMER_LED, time_ms);
  nrf_drv_timer_extended_compare(
  &TIMER_LED, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);

}

static void fsm_subir(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    fp->subir = 1;
    bsp_board_led_on(BSP_BOARD_LED_0);
    deadline=0;
    timer(2000);
}

static void fsm_parar_arriba(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    deadline=0;
    fp->subir = 0;
    fp->bajar = 0;
    bsp_board_leds_off();
    timer(5000);
}

static void fsm_parar_abajo(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    deadline=0;
    fp->subir = 0;
    fp->bajar = 0;
    bsp_board_leds_off();
}

static void fsm_waiting(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    deadline=0;
    timer(3000);
}

static void fsm_bajar(fsm_t *f)
{
    fsm_control_entrada_t *fp = (fsm_control_entrada_t *)f;
    fp->bajar = 1;
    bsp_board_led_on(BSP_BOARD_LED_1);
    deadline=0;
    timer(2000);
}

static fsm_trans_t entrada_tt[] = {
    {DOWN, fsm_NFC, SUBIENDO, fsm_subir},
    {SUBIENDO, fsm_s_bar_top, UP, fsm_parar_arriba},
    {UP, fsm_timer_timeout, BAJANDO, fsm_bajar},
    {UP, fsm_s_prox, WAITING, fsm_waiting},
    {WAITING, fsm_timer_timeout, BAJANDO, fsm_bajar},
    {BAJANDO, fsm_s_bar_bottom, DOWN, fsm_parar_abajo},
    {-1, NULL, -1, NULL}};

void fsm_control_entrada_init(fsm_control_entrada_t *f, fsm_control_entrada_NFC_func_t NFC, fsm_control_entrada_s_bar_top_func_t s_bar_top,
                              fsm_control_entrada_s_prox_func_t s_prox, fsm_control_entrada_s_bar_bottom_func_t s_bar_bottom)
{
    fsm_init((fsm_t *)f, entrada_tt);
    f->subir = 0;
    f->bajar = 0;
    f->deadline = 0;
    f->NFC = NFC;
    f->s_bar_top = s_bar_top;
    f->s_prox = s_prox;
    f->s_bar_bottom = s_bar_bottom;
}
