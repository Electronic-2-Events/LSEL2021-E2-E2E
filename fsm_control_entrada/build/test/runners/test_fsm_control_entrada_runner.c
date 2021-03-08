/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_acciones.h"
#include "mock_timer.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_fsm_Inicial(void);
extern void test_fsm_control_entrada_fsmInitFillsStructWithSomething(void);
extern void test_fsm_control_entrada_fsmFireCallsNFCWhenDown(void);
extern void test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse(void);
extern void test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse(void);
extern void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse(void);
extern void test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse(void);
extern void test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse(void);
extern void test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue(void);
extern void test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_acciones_Init();
  mock_timer_Init();
}
static void CMock_Verify(void)
{
  mock_acciones_Verify();
  mock_timer_Verify();
}
static void CMock_Destroy(void)
{
  mock_acciones_Destroy();
  mock_timer_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_fsm_control_entrada.c");
  run_test(test_fsm_Inicial, "test_fsm_Inicial", 23);
  run_test(test_fsm_control_entrada_fsmInitFillsStructWithSomething, "test_fsm_control_entrada_fsmInitFillsStructWithSomething", 27);
  run_test(test_fsm_control_entrada_fsmFireCallsNFCWhenDown, "test_fsm_control_entrada_fsmFireCallsNFCWhenDown", 38);
  run_test(test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue, "test_fsm_control_entrada_fsmFireFollowsTransitionWhenDownAndNFCIsTrue", 50);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionTransitionWhenDownAndNFCIsFalse", 63);
  run_test(test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue, "test_fsm_control_entrada_fsmFireFollowTransitionWhenSubiendoAndsbartopisTrue", 76);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionWhenSubiendoAndsbartopIsFalse", 92);
  run_test(test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue, "test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndDeadlineisTrue", 109);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndDeadlineisFalse", 125);
  run_test(test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue, "test_fsm_control_entrada_fsmFireFollowTransitionWhenUPAndSProxisTrue", 142);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionWhenUPAndSProxisFalse", 159);
  run_test(test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue, "test_fsm_control_entrada_fsmFireFollowTransitionWhenBajandoAndbarbottomisTrue", 175);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionWhenBajandoAndsbarbottomisFalse", 190);
  run_test(test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue, "test_fsm_control_entrada_fsmFireFollowTransitionWhenWaitingAndDeadlineisTrue", 205);
  run_test(test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse, "test_fsm_control_entrada_fsmFireDontFollowTransitionWhenWaitingAndDeadlineisFalse", 221);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
