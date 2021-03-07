#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_control_pulsera.h"
#include "mock_fsm_control_pulsera_internal.h"
#include "mock_client.h"


void setUp(void)
{
}

void tearDown(void)
{
}

//Rellena la estructura de transiciones de la fsm cuando se inicializa
void test_fsm_control_pulsera_fsmInitFillsStructWithSomething(void)
{
    fsm_control_pulsera_t zero;
    fsm_control_pulsera_t f;
    bzero(&zero, sizeof(fsm_control_pulsera_t));
    bzero(&f, sizeof(fsm_control_pulsera_t));

    fsm_control_pulsera_init(&f, NULL);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_control_pulsera_t)) != 0);
}

//
void test_fsm_control_fsmFireCallsCheckWhenSuspended(void)
{
    fsm_control_pulsera_t f;

    custom_check_ExpectAndReturn(0);

    fsm_control_pulsera_init(&f, custom_check);
    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
    fsm_fire((fsm_t*)(&f));
}

