#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_gestioncolas.h"

#include "mock_fsm_gestioncolas_internal.h"
#include "mock_client.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_fsm_gestioncolas_fsmInitFillsStruct(void)
{
    fsm_gestioncolas_t zero;
    fsm_gestioncolas_t f;
    bzero(&zero, sizeof(fsm_gestioncolas_t));
    bzero(&f, sizeof(fsm_gestioncolas_t));

    fsm_gestioncolas_init(&f, NULL, NULL);
    TEST_ASSERT(memcmp(&zero, &f, sizeof(fsm_gestioncolas_t)) != 0);
}

void test_fsm_gestioncolas_fsmInitListo(void)
{
    fsm_gestioncolas_t f;

    fsm_gestioncolas_init(&f, NULL, NULL);

    TEST_ASSERT_TRUE(f.Listo!=1);
}

void test_fsm_gestioncolas_fsmInitSolicitud(void)
{
    fsm_gestioncolas_t f;

    fsm_gestioncolas_init(&f, NULL, NULL);
    
    TEST_ASSERT_TRUE(f.Solicitud!=1);
}

void test_fsm_gestioncolas_fsmInitOrden(void)
{
    fsm_gestioncolas_t f;

    fsm_gestioncolas_init(&f, NULL, NULL);
    
    TEST_ASSERT_TRUE(f.Orden==0);
}

/*Llamada a funciones*/

void test_fsm_gestioncolas_fsmFireCallsSolicitudColaWhenReady(void)
{
    fsm_gestioncolas_t f;

    custom_solicitud_cola_ExpectAndReturn(1);

    fsm_gestioncolas_init(&f, custom_solicitud_cola, NULL);
    f.fsm.current_state = READY;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_gestioncolas_fsmFireCallsTerminadoWhenWaiting(void)
{
    fsm_gestioncolas_t f;

    custom_terminado_ExpectAndReturn(1);

    fsm_gestioncolas_init(&f, NULL, custom_terminado);
    f.fsm.current_state = WAITING;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_gestioncolas_fsmFireNoCallsSolicitudColaWhenWaiting(void)
{
    fsm_gestioncolas_t f;

    custom_solicitud_cola_IgnoreAndReturn(1);

    fsm_gestioncolas_init(&f, custom_solicitud_cola, NULL);
    f.fsm.current_state = WAITING;
    fsm_fire((fsm_t*)(&f));
}

void test_fsm_gestioncolas_fsmFireNoCallsTerminadoWhenReady(void)
{
    fsm_gestioncolas_t f;

    custom_terminado_IgnoreAndReturn(1);

    fsm_gestioncolas_init(&f, NULL, custom_terminado);
    f.fsm.current_state = READY;
    fsm_fire((fsm_t*)(&f));
}

/*Transiciones*/

void test_fsm_gestioncolas_fsmFireFollowsTransitionWhenReadyAndSolicitudColaTrue(void)
{
    fsm_gestioncolas_t f;

    f.fsm.current_state = READY;
    custom_solicitud_cola_ExpectAndReturn(1);

    fsm_gestioncolas_init(&f, custom_solicitud_cola, NULL);
    fsm_fire((fsm_t*)(&f));

    TEST_ASSERT(f.fsm.current_state == WAITING);
    TEST_ASSERT_TRUE(f.Solicitud == 1);
}

void test_fsm_gestioncolas_fsmFireFollowsTransitionWhenWaitinfAndTerminadoTrue(void)
{
    fsm_gestioncolas_t f;

    custom_terminado_ExpectAndReturn(1);

    fsm_gestioncolas_init(&f, NULL, custom_terminado);

    f.fsm.current_state = WAITING;
    fsm_fire((fsm_t*)(&f));
    
    TEST_ASSERT(f.fsm.current_state == WAITING);
    TEST_ASSERT_TRUE(f.Listo == 1);
}
