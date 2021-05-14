#include "build/temp/_test_fsm_control_pulsera.c"
#include "build/test/mocks/mock_client.h"
#include "build/test/mocks/mock_fsm_control_pulsera_internal.h"
#include "src/fsm_control_pulsera.h"
#include "src/fsm.h"
#include "/usr/local/bundle/gems/ceedling-0.30.0/vendor/unity/src/unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}





void test_fsm_control_pulsera_fsmInitFillsStructWithSomething(void)

{

    fsm_control_pulsera_t zero;

    fsm_control_pulsera_t f;

    bzero(&zero, sizeof(fsm_control_pulsera_t));

    bzero(&f, sizeof(fsm_control_pulsera_t));



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                );

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_pulsera_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(29)));}} while(0);

}



void test_fsm_control_fsmInitStartsWithShowAlarm(void)

{

    fsm_control_pulsera_t f;



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                );

    do {if ((f.menu==SHOW_WARNING)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(37)));}} while(0);

}



void test_fsm_control_fsmInitStartsNFCDeactivated(void)

{

    fsm_control_pulsera_t f;



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , 

                                            ((void*)0)

                                                );

    do {if ((f.NFC_on!=1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(45)));}} while(0);

}





void test_fsm_control_fsmFireCallsActivationWhenSuspended(void)

{

    fsm_control_pulsera_t f;



    custom_activation_CMockExpectAndReturn(53, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , custom_activation, 

                                                         ((void*)0)

                                                             );

    f.fsm.current_state = SUSPENDED;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_fsmFireCallsNoContactWhenIdle(void)

{

    fsm_control_pulsera_t f;



    custom_no_contact_CMockExpectAndReturn(64, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , custom_no_contact);

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_fsmFireCallsGetTimeWhenIdle(void)

{

    fsm_control_pulsera_t f;



    custom_get_time_CMockExpectAndReturn(75, 0);



    fsm_control_pulsera_init(&f, custom_get_time, 

                                                 ((void*)0)

                                                     , 

                                                       ((void*)0)

                                                           );

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));

}





void test_fsm_control_fsmFireNoCallsNoContactWhenSuspended(void)

{

    fsm_control_pulsera_t f;



    custom_no_contact_CMockIgnoreAndReturn(87, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , custom_no_contact);

    f.fsm.current_state = SUSPENDED;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_fsmFireNoCallsGetTimeWhenSuspended(void)

{

    fsm_control_pulsera_t f;



    custom_get_time_CMockIgnoreAndReturn(98, 0);



    fsm_control_pulsera_init(&f, custom_get_time, 

                                                 ((void*)0)

                                                     , 

                                                       ((void*)0)

                                                           );

    f.fsm.current_state = SUSPENDED;

    fsm_fire((fsm_t*)(&f));

}



void test_fsm_control_fsmFireNoCallsActivationWhenIdle(void)

{

    fsm_control_pulsera_t f;



    custom_activation_CMockIgnoreAndReturn(109, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , custom_activation, 

                                                         ((void*)0)

                                                             );

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));

}







void test_fsm_control_fsmFireFollowsTransitionWhenSuspendedAndActivationIsTrue(void)

{

    fsm_control_pulsera_t f;



    custom_activation_CMockExpectAndReturn(122, 1);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , custom_activation, 

                                                         ((void*)0)

                                                             );

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == IDLE)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(127)));}} while(0);

    do {if ((f.menu==SHOW_TIME)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(128)));}} while(0);

    do {if ((f.NFC_on == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(129)));}} while(0);

}



void test_fsm_control_fsmFireFollowsTransitionWhenIdleAndNoContactIsTrue(void)

{

    fsm_control_pulsera_t f;



    custom_no_contact_CMockExpectAndReturn(136, 1);

    custom_get_time_CMockIgnoreAndReturn(137, 0);



    fsm_control_pulsera_init(&f, custom_get_time, 

                                                 ((void*)0)

                                                     , custom_no_contact);

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUSPENDED)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(143)));}} while(0);

    do {if ((f.menu == SHOW_WARNING)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(144)));}} while(0);

    do {if ((f.NFC_on == 0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(145)));}} while(0);

}



void test_fsm_control_fsmFireFollowsTransitionWhenIdleAndGetTimeIsTrue(void)

{

    fsm_control_pulsera_t f;



    custom_get_time_CMockExpectAndReturn(152, 1);



    fsm_control_pulsera_init(&f, custom_get_time, 

                                                 ((void*)0)

                                                     , 

                                                       ((void*)0)

                                                           );

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == IDLE)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(158)));}} while(0);

}





void test_fsm_rebound_fsmFireDontFollowTransitionWhenSuspendedAndActivationIsFalse(void)

{

    fsm_control_pulsera_t f;



    custom_activation_CMockIgnoreAndReturn(166, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , custom_activation, 

                                                         ((void*)0)

                                                             );

    f.fsm.current_state = SUSPENDED;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == SUSPENDED)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(172)));}} while(0);

}



void test_fsm_rebound_fsmFireDontFollowTransitionWhenIdleAndNoContactIsFalse(void)

{

    fsm_control_pulsera_t f;



    custom_no_contact_CMockIgnoreAndReturn(179, 0);



    fsm_control_pulsera_init(&f, 

                                ((void*)0)

                                    , 

                                      ((void*)0)

                                          , custom_no_contact);

    f.fsm.current_state = IDLE;

    fsm_fire((fsm_t*)(&f));



    do {if ((f.fsm.current_state == IDLE)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(185)));}} while(0);

}





void test_fsm_control_pulsera_fsmFireComplete(void)

{

    fsm_control_pulsera_t f;



    fsm_control_pulsera_init(&f, custom_get_time, custom_activation, custom_no_contact);

    custom_activation_CMockExpectAndReturn(194, 0);

    fsm_fire(&(f.fsm));

    do {if ((f.fsm.current_state == SUSPENDED)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(196)));}} while(0);

    do {if ((f.menu == SHOW_WARNING)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(197)));}} while(0);

    do {if ((f.NFC_on == 0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(198)));}} while(0);



    custom_activation_CMockExpectAndReturn(200, 1);

    fsm_fire(&(f.fsm));

    do {if ((f.fsm.current_state == IDLE)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(202)));}} while(0);

    do {if ((f.menu == SHOW_TIME)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(203)));}} while(0);

    do {if ((f.NFC_on == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(204)));}} while(0);



    custom_get_time_CMockExpectAndReturn(206, 1);

    fsm_fire(&(f.fsm));

    do {if ((f.fsm.current_state == IDLE)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(208)));}} while(0);

    do {if ((f.menu == SHOW_TIME)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(209)));}} while(0);

    do {if ((f.NFC_on == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(210)));}} while(0);



    custom_get_time_CMockExpectAndReturn(212, 0);

    custom_no_contact_CMockExpectAndReturn(213, 1);

    fsm_fire(&(f.fsm));

    do {if ((f.fsm.current_state == SUSPENDED)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(215)));}} while(0);

    do {if ((f.menu == SHOW_WARNING)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(216)));}} while(0);

    do {if ((f.NFC_on == 0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(217)));}} while(0);

}
