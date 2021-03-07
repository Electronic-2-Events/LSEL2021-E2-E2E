#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#include "mock_acciones.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_fsm_rebound_fsmInitFillsStructWithSomething(void)
{
    fsm_rebound_t zero;
    fsm_rebound_t f;
    bzero(&zero, sizeof(fsm_rebound_t));
    bzero(&f, sizeof(fsm_rebound_t));

    fsm_rebound_init(&f, NULL, NULL, 0);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_rebound_t)) != 0);
}
