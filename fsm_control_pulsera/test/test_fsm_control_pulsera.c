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

// Comprobar la inicializacion
void test_fsm_control_pulsera_fsmInitFillsStructWithSomething(void)
{
    fsm_control_pulsera_t zero;
    fsm_control_pulsera_t f;
    bzero(&zero, sizeof(fsm_control_pulsera_t));
    bzero(&f, sizeof(fsm_control_pulsera_t));

    fsm_control_pulsera_init(&f, NULL, NULL, NULL);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_control_pulsera_t)) != 0);
}

void test_fsm_control_fsmInitStartsWithShowAlarm(void)
{
    fsm_control_pulsera_t f;

    fsm_control_pulsera_init(&f, NULL, NULL, NULL);
    TEST_ASSERT_TRUE(f.menu==SHOW_WARNING);
}

void test_fsm_control_fsmInitStartsNFCDeactivated(void)
{
    fsm_control_pulsera_t f;

    fsm_control_pulsera_init(&f, NULL, NULL, NULL);
    TEST_ASSERT_TRUE(f.NFC_on!=1);
}

// Llama a funciones correctamente
void test_fsm_control_fsmFireCallsActivationWhenSuspended(void)
{
    fsm_control_pulsera_t f;

    custom_activation_ExpectAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, custom_activation, NULL);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireCallsNoContactWhenIdle(void)
{
    fsm_control_pulsera_t f;

    custom_no_contact_ExpectAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, NULL, custom_no_contact);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireCallsGetTimeWhenIdle(void)
{
    fsm_control_pulsera_t f;

    custom_get_time_ExpectAndReturn(0);

    fsm_control_pulsera_init(&f, custom_get_time, NULL, NULL);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));
}

// No llama a funciones que no debe llamar
void test_fsm_control_fsmFireNoCallsNoContactWhenSuspended(void)
{
    fsm_control_pulsera_t f;

    custom_no_contact_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, NULL, custom_no_contact);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireNoCallsGetTimeWhenSuspended(void)
{
    fsm_control_pulsera_t f;

    custom_get_time_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, custom_get_time, NULL, NULL);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireNoCallsActivationWhenIdle(void)
{
    fsm_control_pulsera_t f;

    custom_activation_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, custom_activation, NULL);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));
}

//Comprobar transiciones normales
//Transiciones
void test_fsm_control_fsmFireFollowsTransitionWhenSuspendedAndActivationIsTrue(void)
{
    fsm_control_pulsera_t f;

    custom_activation_ExpectAndReturn(1);

    fsm_control_pulsera_init(&f, NULL, custom_activation, NULL);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == IDLE);
    TEST_ASSERT_TRUE(f.menu==SHOW_TIME);
    TEST_ASSERT_TRUE(f.NFC_on == 1);
}

void test_fsm_control_fsmFireFollowsTransitionWhenIdleAndNoContactIsTrue(void)
{
    fsm_control_pulsera_t f;

    custom_no_contact_ExpectAndReturn(1);
    custom_get_time_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, custom_get_time, NULL, custom_no_contact);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
    TEST_ASSERT_TRUE(f.menu == SHOW_WARNING);
    TEST_ASSERT_TRUE(f.NFC_on == 0);
}

void test_fsm_control_fsmFireFollowsTransitionWhenIdleAndGetTimeIsTrue(void)
{
    fsm_control_pulsera_t f;

    custom_get_time_ExpectAndReturn(1);

    fsm_control_pulsera_init(&f, custom_get_time, NULL, NULL);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == IDLE);
}

// No transiciones
void test_fsm_rebound_fsmFireDontFollowTransitionWhenSuspendedAndActivationIsFalse(void)
{
    fsm_control_pulsera_t f;

    custom_activation_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, custom_activation, NULL);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
}

void test_fsm_rebound_fsmFireDontFollowTransitionWhenIdleAndNoContactIsFalse(void)
{
    fsm_control_pulsera_t f;

    custom_no_contact_IgnoreAndReturn(0);

    fsm_control_pulsera_init(&f, NULL, NULL, custom_no_contact);
    f.fsm.current_state = IDLE;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == IDLE);
}

// Test funcionalidad global ciclo normal
void test_fsm_control_pulsera_fsmFireComplete(void)
{
    fsm_control_pulsera_t f;

    fsm_control_pulsera_init(&f, custom_get_time, custom_activation, custom_no_contact);
    custom_activation_ExpectAndReturn(0);
    fsm_fire(&(f.fsm));
    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
    TEST_ASSERT_TRUE(f.menu == SHOW_WARNING);
    TEST_ASSERT_TRUE(f.NFC_on == 0);

    custom_activation_ExpectAndReturn(1);
    fsm_fire(&(f.fsm));
    TEST_ASSERT(f.fsm.current_state == IDLE);
    TEST_ASSERT_TRUE(f.menu == SHOW_TIME);
    TEST_ASSERT_TRUE(f.NFC_on == 1);

    custom_get_time_ExpectAndReturn(1);
    fsm_fire(&(f.fsm));
    TEST_ASSERT(f.fsm.current_state == IDLE);
    TEST_ASSERT_TRUE(f.menu == SHOW_TIME);
    TEST_ASSERT_TRUE(f.NFC_on == 1);
    
    custom_get_time_ExpectAndReturn(0);
    custom_no_contact_ExpectAndReturn(1);
    fsm_fire(&(f.fsm));
    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
    TEST_ASSERT_TRUE(f.menu == SHOW_WARNING);
    TEST_ASSERT_TRUE(f.NFC_on == 0);
}
