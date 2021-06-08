#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_control_entrada.h"
#include "fsm_control_entrada_internal.h"

#include "mock_acciones.h"
#include "mock_timer.h"

#define DEADLINE10 (10)
#define DEADLINE3 (3)

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

    fsm_control_entrada_init(&f, NULL, NULL, NULL, NULL);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0);
}

void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(1);

    fsm_control_entrada_init(&f, NFC, NULL, NULL, NULL);

    TEST_ASSERT(f.fsm.current_state == DOWN);
    fsm_fire((fsm_t *)(&f));
}

void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(2);

    fsm_control_entrada_init(&f, NFC, NULL, NULL, NULL);
    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == SUBIENDO);
    TEST_ASSERT(f.subir == 1);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)
{
    fsm_control_entrada_t f;

    NFC_ExpectAndReturn(10);

    fsm_control_entrada_init(&f, NFC, NULL, NULL, NULL);
    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == DOWN);
    TEST_ASSERT(f.subir == 0);
}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void)
{
    fsm_control_entrada_t f;

    s_bar_top_ExpectAndReturn(1);
    timer_ExpectAndReturn(0);

    fsm_control_entrada_init(&f, NFC, s_bar_top, NULL, NULL);
    f.fsm.current_state = SUBIENDO;
    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == UP);
    TEST_ASSERT(f.subir == 0);
    TEST_ASSERT(f.next_timeout == DEADLINE10);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void)
{
    fsm_control_entrada_t f;
    s_bar_top_ExpectAndReturn(0);

    fsm_control_entrada_init(&f, NFC, s_bar_top, NULL, NULL);
    f.fsm.current_state = SUBIENDO;
    f.subir = 1;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == SUBIENDO);
    TEST_ASSERT(f.subir == 1);
}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)
{
    fsm_control_entrada_t f;

    timer_ExpectAndReturn(12);

    fsm_control_entrada_init(&f, NULL, NULL, NULL, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = UP;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == BAJANDO);
    TEST_ASSERT(f.bajar == 1);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)
{
    fsm_control_entrada_t f;

    timer_ExpectAndReturn(8);
    s_prox_IgnoreAndReturn(0);

    fsm_control_entrada_init(&f, NULL, NULL, s_prox, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = UP;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == UP);
    TEST_ASSERT(f.bajar == 0);
}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)
{
    fsm_control_entrada_t f;

    timer_IgnoreAndReturn(1);
    s_prox_IgnoreAndReturn(1);

    fsm_control_entrada_init(&f, NULL, NULL, s_prox, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = UP;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == WAITING);
    TEST_ASSERT(f.next_timeout == 1 + 3);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)
{
    fsm_control_entrada_t f;

    timer_IgnoreAndReturn(1);
    s_prox_IgnoreAndReturn(0);

    fsm_control_entrada_init(&f, NULL, NULL, s_prox, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = UP;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == UP);
}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void)
{
    fsm_control_entrada_t f;

    timer_IgnoreAndReturn(1);
    s_bar_bottom_ExpectAndReturn(1);

    fsm_control_entrada_init(&f, NULL, NULL, NULL, s_bar_bottom);
    f.fsm.current_state = BAJANDO;
    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == DOWN);
    TEST_ASSERT(f.bajar == 0);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void)
{
    fsm_control_entrada_t f;

    s_bar_bottom_ExpectAndReturn(0);

    fsm_control_entrada_init(&f, NFC, NULL, NULL, s_bar_bottom);
    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == BAJANDO);
    TEST_ASSERT(f.bajar == 0);
}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void)
{
    fsm_control_entrada_t f;

    timer_ExpectAndReturn(11);

    fsm_control_entrada_init(&f, NULL, NULL, NULL, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = WAITING;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == BAJANDO);
    TEST_ASSERT(f.bajar == 1);
}

void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void)
{
    fsm_control_entrada_t f;

    timer_ExpectAndReturn(9);
    s_prox_IgnoreAndReturn(0);

    fsm_control_entrada_init(&f, NULL, NULL, s_prox, NULL);
    f.next_timeout = 10;
    f.fsm.current_state = WAITING;

    fsm_fire((fsm_t *)(&f));

    TEST_ASSERT(f.fsm.current_state == WAITING);
    TEST_ASSERT(f.bajar == 0);
}
