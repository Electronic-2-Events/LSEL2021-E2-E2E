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

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));}} while(0);

}







void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(46, 1);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);

    fsm_fire((fsm_t *)(&f));

}

void test_fsm_control_entrada_fsmFireDontCallsAnythingElseWhenDown(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(57, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);



    fsm_fire((fsm_t *)(&f));

}



void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(68, 1);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , 

                                                 ((void*)0)

                                                     );

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(73)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(74)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(81, 0);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , 

                                                 ((void*)0)

                                                     );

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(86)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

}







void test_fsm_control_entrada_fsmFireCallsS_bar_topWhenSubiendo(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(96, 1);

    timer_CMockExpectAndReturn(97, 10);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);

    f.fsm.current_state = SUBIENDO;



    fsm_fire((fsm_t *)(&f));

    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(103)));}} while(0);



}

void test_fsm_control_entrada_fsmFireDontCallsAnythingElseWhenSubiendo(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(110, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);

    f.fsm.current_state = SUBIENDO;



    fsm_fire((fsm_t *)(&f));

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(122, 1);

    timer_CMockExpectAndReturn(123, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, 

                                                ((void*)0)

                                                    , 

                                                      ((void*)0)

                                                          );

    f.fsm.current_state = SUBIENDO;

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(129)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(130)));}} while(0);

    do {if ((f.next_timeout == (10))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockIgnoreAndReturn(138, 1);

    s_bar_top_CMockExpectAndReturn(139, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, 

                                                ((void*)0)

                                                    , 

                                                      ((void*)0)

                                                          );



    fsm_fire((fsm_t *)(&f));



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(147)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(148)));}} while(0);

}







void test_fsm_control_entrada_fsmFireCallsTimerAndS_proxWhenUp(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(157, 0);

    s_prox_CMockExpectAndReturn(158, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);

    f.fsm.current_state = UP;

    f.next_timeout = 10;



    fsm_fire((fsm_t *)(&f));

    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(165)));}} while(0);



}



void test_fsm_control_entrada_fsmFireDontCallsAnythingElseWhenUp(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(173, 0);

    s_prox_CMockExpectAndReturn(174, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, s_prox, s_bar_bottom);

    f.fsm.current_state = UP;

    f.next_timeout = 10;



    fsm_fire((fsm_t *)(&f));

}

void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(186, 12);



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



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(194)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(195)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(202, 8);

    s_prox_CMockIgnoreAndReturn(203, 0);



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



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(211)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(212)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(219, 1);

    s_prox_CMockIgnoreAndReturn(220, 1);



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



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(228)));}} while(0);

    do {if ((f.next_timeout == 1 + 3)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(229)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(236, 1);

    s_prox_CMockIgnoreAndReturn(237, 0);



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



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(245)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(252, 1);

    s_bar_bottom_CMockExpectAndReturn(253, 1);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , s_bar_bottom);

    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(259)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(260)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void)

{

    fsm_control_entrada_t f;



    s_bar_bottom_CMockExpectAndReturn(267, 0);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , s_bar_bottom);

    f.fsm.current_state = BAJANDO;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(274)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(275)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(282, 11);



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



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(290)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(291)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(298, 9);

    s_prox_CMockIgnoreAndReturn(299, 0);



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



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(307)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(308)));}} while(0);

}
