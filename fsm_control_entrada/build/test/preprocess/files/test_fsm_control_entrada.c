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



<<<<<<< HEAD

void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(118, 12);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(126)));}} while(0);

    do {if ((f.bajar == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(127)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockExpectAndReturn(134, 8);

    s_prox_CMockIgnoreAndReturn(135, 0);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(143)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(144)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(151, 1);

    s_prox_CMockIgnoreAndReturn(152, 1);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == WAITING)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(160)));}} while(0);

    do {if ((f.next_timeout == 1+3)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(161)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void)

{

    fsm_control_entrada_t f;



    timer_CMockIgnoreAndReturn(168, 1);

    s_prox_CMockIgnoreAndReturn(169, 0);



    fsm_control_entrada_init(&f);

    f.next_timeout = 10;

    f.fsm.current_state = UP;



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(177)));}} while(0);

}

=======

void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndBarBottomisTrue(void)

{

    fsm_control_entrada_t f;



    s_bar_bottom_CMockExpectAndReturn(184, 1);



    fsm_control_entrada_init(&f);

    f.fsm.current_state = BAJANDO;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(190)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(191)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndBarBottomisFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockIgnoreAndReturn(198, 1);

    s_bar_bottom_CMockExpectAndReturn(199, 1);



    fsm_control_entrada_init(&f);



    fsm_fire((fsm_t*)(&f));



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == BAJANDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(207)));}} while(0);

    do {if ((f.bajar == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(208)));}} while(0);

}

>>>>>>> 798385e9c0dc9a5d5e00ed50fce30feb56924960
