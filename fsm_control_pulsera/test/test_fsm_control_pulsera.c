#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_control.h"
#include "mock_fsm_control_internal.h"

#include "mock_client.h"
#include "mock_timer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_fsm_control_fsmInitFillsStructWithSomething(void)
{
    fsm_control_t zero;
    fsm_control_t f;
    bzero(&zero, sizeof(fsm_control_t));
    bzero(&f, sizeof(fsm_control_t));

    fsm_control_init(&f, NULL);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_control_t)) != 0);
}

void test_fsm_control_fsmFireCallsCheckWhenReady(void)
{
    fsm_control_t f;

    custom_check_ExpectAndReturn(0);

    fsm_control_init(&f, custom_check);
    TEST_ASSERT(f.fsm.current_state == READY);
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireNoCallsCheckWhenSuspended(void)
{
    fsm_control_t f;

    timer_get_tick_IgnoreAndReturn(0);

    fsm_control_init(&f, custom_check);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireFollowsTransitionWhenReadyAndCheckIsTrue(void)
{
    TEST_IGNORE();
    fsm_control_t f;

    custom_check_IgnoreAndReturn(1);
    timer_get_tick_IgnoreAndReturn(0);

    fsm_control_init(&f, custom_check);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
}

void test_fsm_control_fsmFireDontFollowTransitionWhenReadyAndCheckIsFalse(void)
{
    
    fsm_control_t f;

    custom_check_IgnoreAndReturn(0);

    fsm_control_init(&f, custom_check);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == READY);
}

void test_fsm_control_fsmFireCallsGetTickWhenReady(void)
{
    fsm_control_t f;

    timer_get_tick_ExpectAndReturn(0);

    fsm_control_init(&f, NULL);
    f.fsm.current_state = SUSPENDED;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireNoCallsGetTickWhenSuspended(void)
{
    fsm_control_t f;

    fsm_control_init(&f, NULL);
    TEST_ASSERT(f.fsm.current_state == READY);
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_control_fsmFireFollowsTransitionWhenSuspendedAndIsTimeout(void)
{
    TEST_IGNORE();
    fsm_control_t f;
    timer_get_tick_ExpectAndReturn(1);

    fsm_control_init(&f, NULL);
    f.fsm.current_state = SUSPENDED;
    f.timeout = 0;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == READY);
}

void test_fsm_control_fsmFireDontFollowTransitionWhenSuspendedAndIsNoTimeout(void)
{
    TEST_IGNORE();
    fsm_control_t f;

    custom_check_IgnoreAndReturn(1);
    timer_get_tick_ExpectAndReturn(0);

    fsm_control_init(&f, NULL);
    f.fsm.current_state = SUSPENDED;
    f.timeout = 0;
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == SUSPENDED);
}