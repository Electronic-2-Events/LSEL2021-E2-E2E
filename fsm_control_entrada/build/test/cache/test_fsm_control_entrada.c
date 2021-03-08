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



    NFC_CMockExpectAndReturn(54, 4545);



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



    NFC_CMockExpectAndReturn(67, 0);



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



    NFC_CMockIgnoreAndReturn(96, 1);

    s_bar_top_CMockExpectAndReturn(97, 0);



    fsm_control_entrada_init(&f, NFC, s_bar_top, 

                                                ((void*)0)

                                                    , 

                                                      ((void*)0)

                                                          );



    fsm_fire((fsm_t *)(&f));



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(105)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(106)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(113, 12);



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



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(122)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(129, 8);

    s_prox_CMockIgnoreAndReturn(130, 0);



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



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(138)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(139)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(146, 1);

    s_prox_CMockIgnoreAndReturn(147, 1);



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



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(155)));}} while(0);

    do {if ((f.next_timeout == 1 + 3)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(156)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(163, 1);

    s_prox_CMockIgnoreAndReturn(164, 0);



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



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(172)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(179, 1);

    s_bar_bottom_CMockExpectAndReturn(180, 1);



    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , s_bar_bottom);

    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(186)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(187)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void)

{

    fsm_control_entrada_t f;



    s_bar_bottom_CMockExpectAndReturn(194, 0);



    fsm_control_entrada_init(&f, NFC, 

                                     ((void*)0)

                                         , 

                                           ((void*)0)

                                               , s_bar_bottom);

    f.fsm.current_state = BAJANDO;



    fsm_fire((fsm_t *)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(201)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(202)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(209, 11);



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



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(217)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(218)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(225, 9);

    s_prox_CMockIgnoreAndReturn(226, 0);



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



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(234)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(235)));}} while(0);

}







void test_fsm_control_entrada_fsmFireFollowTransitionWhenDownAndNFCIDisValid(void)

{

    fsm_control_entrada_t f;





    fsm_control_entrada_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                , 

                                                  ((void*)0)

                                                      );



    f.fsm.current_state = DOWN;



    fsm_fire((fsm_t *)(&f));







}
