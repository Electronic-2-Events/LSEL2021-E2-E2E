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

   ), (UNITY_UINT)(27));

}

void test_fsm_control_entrada_fsmInitFillsStructWithSomething(void)

{

    fsm_control_entrada_t zero;

    fsm_control_entrada_t f;

    bzero(&zero, sizeof(fsm_control_entrada_t));

    bzero(&f, sizeof(fsm_control_entrada_t));



    fsm_control_entrada_init(&f);

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));}} while(0);

}



void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(44, 1);



    fsm_control_entrada_init(&f);



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(56, 1);



    fsm_control_entrada_init(&f);

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(61)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));}} while(0);



}



void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(70, 0);



    fsm_control_entrada_init(&f);

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(76)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(83, 1);

    timer_CMockExpectAndReturn(84, 0);



    fsm_control_entrada_init(&f);

    f.fsm.current_state = SUBIENDO;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(90)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));}} while(0);

    do {if ((f.next_timeout ==(10))) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));}} while(0);



}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockIgnoreAndReturn(100, 1);

    s_bar_top_CMockExpectAndReturn(101, 0);



    fsm_control_entrada_init(&f);



    fsm_fire((fsm_t*)(&f));



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(109)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(110)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(117, 12);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(125)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(126)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(133, 8);

    s_prox_CMockIgnoreAndReturn(134, 0);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(142)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(143)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(150, 1);

    s_prox_CMockIgnoreAndReturn(151, 1);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(159)));}} while(0);

    do {if ((f.next_timeout == 1+3)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(160)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(167, 1);

    s_prox_CMockIgnoreAndReturn(168, 0);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(176)));}} while(0);

}







void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(185, 1);

    s_bar_bottom_CMockExpectAndReturn(186, 1);



    fsm_control_entrada_init(&f);

    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(192)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(193)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockIgnoreAndReturn(200, 1);



    s_bar_bottom_CMockExpectAndReturn(202, 0);



    fsm_control_entrada_init(&f);





    fsm_fire((fsm_t*)(&f));

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(210)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(211)));}} while(0);

}





void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(219, 11);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = WAITING;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(227)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(228)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(235, 9);

    s_prox_CMockIgnoreAndReturn(236, 0);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = WAITING;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(244)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(245)));}} while(0);

}
