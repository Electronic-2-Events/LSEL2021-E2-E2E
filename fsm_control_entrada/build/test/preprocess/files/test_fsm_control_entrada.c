#include "build/temp/_test_fsm_control_entrada.c"
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

   ), (UNITY_UINT)(21));

}

void test_fsm_control_entrada_fsmInitFillsStructWithSomething(void)

{

    fsm_control_entrada_t zero;

    fsm_control_entrada_t f;

    bzero(&zero, sizeof(fsm_control_entrada_t));

    bzero(&f, sizeof(fsm_control_entrada_t));



    fsm_control_entrada_init(&f);

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_entrada_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(31)));}} while(0);

}



void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(38, 1);



    fsm_control_entrada_init(&f);



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(42)));}} while(0);

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(50, 1);



    fsm_control_entrada_init(&f);

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(55)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(56)));}} while(0);



}



void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(64, 0);



    fsm_control_entrada_init(&f);

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == DOWN)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(69)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

}



void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void)

{

    fsm_control_entrada_t f;



    s_bar_top_CMockExpectAndReturn(77, 1);



    fsm_control_entrada_init(&f);

    f.fsm.current_state = SUBIENDO;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == UP)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(83)));}} while(0);

    do {if ((f.subir == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(84)));}} while(0);

}



void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void)

{

    fsm_control_entrada_t f;



    NFC_CMockExpectAndReturn(91, 1);

    s_bar_top_CMockExpectAndReturn(92, 0);



    fsm_control_entrada_init(&f);



    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUBIENDO)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(98)));}} while(0);

    do {if ((f.subir == 1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(99)));}} while(0);

}
