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

void test_fsm_Inicial(void)
{
    TEST_IGNORE();
}
void test_fsm_control_entrada_fsmInitFillsStructWithSomething(void)
{
    fsm_control_entrada_t zero;
    fsm_control_entrada_t f;
    bzero(&zero, sizeof(fsm_control_entrada_t));
    bzero(&f, sizeof(fsm_control_entrada_t));

    fsm_control_entrada_init(&f);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0);
}

void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(1);

    fsm_control_entrada_init(&f);

    TEST_ASSERT(f.fsm.current_state == DOWN);
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(1);

    fsm_control_entrada_init(&f);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == SUBIENDO);
    TEST_ASSERT(f.subir == 1);

}

void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(0);

    fsm_control_entrada_init(&f);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == DOWN);
    TEST_ASSERT(f.subir == 0);
}

//hola

//hola2