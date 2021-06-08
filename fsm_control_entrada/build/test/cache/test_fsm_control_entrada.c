#include "build/temp/_test_fsm_control_entrada.c"
#include "build/test/mocks/mock_timer.h"
#include "build/test/mocks/mock_acciones.h"
#include "src/fsm_control_entrada_internal.h"
#include "src/fsm_control_entrada.h"
#include "src/fsm.h"
#include "/usr/local/bundle/gems/ceedling-0.30.0/vendor/unity/src/unity.h"














void setUp(void)

{

}



void tearDown(void)

{

}



void test_fsm_Inicial(void)

{

    UnityIgnore( (

   ((void*)0)

   ), (UNITY_UINT)(25));

}

void test_fsm_control_entrada_fsmInitFillsStructWithSomething(void)

{

    fsm_control_entrada_t zero;

    fsm_control_entrada_t f;

    bzero(&zero, sizeof(fsm_control_entrada_t));

    bzero(&f, sizeof(fsm_control_entrada_t));



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , 

                                                  ((void*)0)

                                                      );

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);

}



void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(42, 1);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , 

                                                 ((void*)0)

                                                     );



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(46)));}} while(0);

    fsm_fire((fsm_t *)(&f));

}



void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(54, 2);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , 

                                                 ((void*)0)

                                                     );

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(60)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(67, 10);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , 

                                                 ((void*)0)

                                                     );

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(80, 1);

    timer_CMockExpectAndReturn(81, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, 

                                                ((void*)0)

                                                    , 

                                                      ((void*)0)

                                                          );

    f.fsm.current_state = SUBIENDO;

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(88)));}} while(0);

    do {if ((f.next_timeout == (10))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(89)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void)

{

    fsm_control_entrada_t f;

    s_bar_top_CMockExpectAndReturn(95, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, 

                                                ((void*)0)

                                                    , 

                                                      ((void*)0)

                                                          );

    f.fsm.current_state = SUBIENDO;

    f.subir = 1;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(103)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(104)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(111, 12);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , 

                                                  ((void*)0)

                                                      );

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(119)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(127, 8);

    s_prox_CMockIgnoreAndReturn(128, 0);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , s_prox, 

                                                    ((void*)0)

                                                        );

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(136)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(137)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(144, 1);

    s_prox_CMockIgnoreAndReturn(145, 1);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , s_prox, 

                                                    ((void*)0)

                                                        );

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(153)));}} while(0);

    do {if ((f.next_timeout == 1 + 3)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(154)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(161, 1);

    s_prox_CMockIgnoreAndReturn(162, 0);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , s_prox, 

                                                    ((void*)0)

                                                        );

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(170)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(177, 1);

    s_bar_bottom_CMockExpectAndReturn(178, 1);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , s_bar_bottom);

    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(184)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(185)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void)

{

    fsm_control_entrada_t f;



    s_bar_bottom_CMockExpectAndReturn(192, 0);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , s_bar_bottom);

    f.fsm.current_state = BAJANDO;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(199)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(200)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(207, 11);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , 

                                                  ((void*)0)

                                                      );

    f.next_timeout = 10;

    f.fsm.current_state = WAITING;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(215)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(216)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(223, 9);

    s_prox_CMockIgnoreAndReturn(224, 0);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , s_prox, 

                                                    ((void*)0)

                                                        );

    f.next_timeout = 10;

    f.fsm.current_state = WAITING;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(232)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(233)));}} while(0);

}
