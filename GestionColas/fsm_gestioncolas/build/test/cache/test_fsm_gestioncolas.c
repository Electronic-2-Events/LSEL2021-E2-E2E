#include "build/temp/_test_fsm_gestioncolas.c"
#include "build/test/mocks/mock_client.h"
#include "build/test/mocks/mock_fsm_gestioncolas_internal.h"
#include "src/fsm_gestioncolas.h"
#include "src/fsm.h"
#include "/usr/local/bundle/gems/ceedling-0.30.0/vendor/unity/src/unity.h"








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



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , 

                                   ((void*)0)

                                       );

    do {if ((memcmp(&zero, &f, sizeof(fsm_gestioncolas_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

}



void test_fsm_gestioncolas_fsmInitListo(void)

{

    fsm_gestioncolas_t f;



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , 

                                   ((void*)0)

                                       );



    do {if ((f.Listo!=1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

}



void test_fsm_gestioncolas_fsmInitSolicitud(void)

{

    fsm_gestioncolas_t f;



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , 

                                   ((void*)0)

                                       );



    do {if ((f.Solicitud!=1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(45)));}} while(0);

}



void test_fsm_gestioncolas_fsmInitOrden(void)

{

    fsm_gestioncolas_t f;



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , 

                                   ((void*)0)

                                       );



    do {if ((f.Orden==0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(54)));}} while(0);

}







void test_fsm_gestioncolas_fsmFireCallsSolicitudColaWhenReady(void)

{

    fsm_gestioncolas_t f;



    custom_solicitud_cola_CMockExpectAndReturn(63, 1);



    fsm_gestioncolas_init(&f, custom_solicitud_cola, 

                                                    ((void*)0)

                                                        );

    f.fsm.current_state = READY;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_gestioncolas_fsmFireCallsTerminadoWhenWaiting(void)

{

    fsm_gestioncolas_t f;



    custom_terminado_CMockExpectAndReturn(74, 1);



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , custom_terminado);

    f.fsm.current_state = WAITING;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_gestioncolas_fsmFireNoCallsSolicitudColaWhenWaiting(void)

{

    fsm_gestioncolas_t f;



    custom_solicitud_cola_CMockIgnoreAndReturn(85, 1);



    fsm_gestioncolas_init(&f, custom_solicitud_cola, 

                                                    ((void*)0)

                                                        );

    f.fsm.current_state = WAITING;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_gestioncolas_fsmFireNoCallsTerminadoWhenReady(void)

{

    fsm_gestioncolas_t f;



    custom_terminado_CMockIgnoreAndReturn(96, 1);



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , custom_terminado);

    f.fsm.current_state = READY;

    fsm_fire((fsm_t*)(&f));

}







void test_fsm_gestioncolas_fsmFireFollowsTransitionWhenReadyAndSolicitudColaTrue(void)

{

    fsm_gestioncolas_t f;



    f.fsm.current_state = READY;

    custom_solicitud_cola_CMockExpectAndReturn(110, 1);



    fsm_gestioncolas_init(&f, custom_solicitud_cola, 

                                                    ((void*)0)

                                                        );

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(115)));}} while(0);

    do {if ((f.Solicitud == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(116)));}} while(0);

}



void test_fsm_gestioncolas_fsmFireFollowsTransitionWhenWaitinfAndTerminadoTrue(void)

{

    fsm_gestioncolas_t f;



    custom_terminado_CMockExpectAndReturn(123, 1);



    fsm_gestioncolas_init(&f, 

                             ((void*)0)

                                 , custom_terminado);



    f.fsm.current_state = WAITING;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(130)));}} while(0);

    do {if ((f.Listo == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));}} while(0);

}
