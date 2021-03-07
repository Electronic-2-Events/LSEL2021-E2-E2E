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

                                    );

    do {if ((memcmp(&zero, &f, sizeof(fsm_control_pulsera_t)) != 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

}





void test_fsm_control_fsmFireCallsCheckWhenSuspended(void)

{

    fsm_control_pulsera_t f;



    custom_check_CMockExpectAndReturn(36, 0);



    fsm_control_pulsera_init(&f, custom_check);

    do {if ((f.fsm.current_state == SUSPENDED)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(39)));}} while(0);

    fsm_fire((fsm_t*)(&f));

}
