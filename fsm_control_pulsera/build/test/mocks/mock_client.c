/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_client.h"

static const char* CMockString_custom_activation = "custom_activation";
static const char* CMockString_custom_get_time = "custom_get_time";
static const char* CMockString_custom_no_contact = "custom_no_contact";

typedef struct _CMOCK_custom_no_contact_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  int CallOrder;

} CMOCK_custom_no_contact_CALL_INSTANCE;

typedef struct _CMOCK_custom_activation_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  int CallOrder;

} CMOCK_custom_activation_CALL_INSTANCE;

typedef struct _CMOCK_custom_get_time_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  int CallOrder;

} CMOCK_custom_get_time_CALL_INSTANCE;

static struct mock_clientInstance
{
  char custom_no_contact_IgnoreBool;
  int custom_no_contact_FinalReturn;
  char custom_no_contact_CallbackBool;
  CMOCK_custom_no_contact_CALLBACK custom_no_contact_CallbackFunctionPointer;
  int custom_no_contact_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE custom_no_contact_CallInstance;
  char custom_activation_IgnoreBool;
  int custom_activation_FinalReturn;
  char custom_activation_CallbackBool;
  CMOCK_custom_activation_CALLBACK custom_activation_CallbackFunctionPointer;
  int custom_activation_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE custom_activation_CallInstance;
  char custom_get_time_IgnoreBool;
  int custom_get_time_FinalReturn;
  char custom_get_time_CallbackBool;
  CMOCK_custom_get_time_CALLBACK custom_get_time_CallbackFunctionPointer;
  int custom_get_time_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE custom_get_time_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_client_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.custom_no_contact_CallInstance;
  if (Mock.custom_no_contact_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_custom_no_contact);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.custom_no_contact_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.custom_activation_CallInstance;
  if (Mock.custom_activation_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_custom_activation);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.custom_activation_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.custom_get_time_CallInstance;
  if (Mock.custom_get_time_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_custom_get_time);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.custom_get_time_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_client_Init(void)
{
  mock_client_Destroy();
}

void mock_client_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int custom_no_contact(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_custom_no_contact_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_custom_no_contact);
  cmock_call_instance = (CMOCK_custom_no_contact_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.custom_no_contact_CallInstance);
  Mock.custom_no_contact_CallInstance = CMock_Guts_MemNext(Mock.custom_no_contact_CallInstance);
  if (Mock.custom_no_contact_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.custom_no_contact_FinalReturn;
    Mock.custom_no_contact_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.custom_no_contact_CallbackBool &&
      Mock.custom_no_contact_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.custom_no_contact_CallbackFunctionPointer(Mock.custom_no_contact_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.custom_no_contact_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.custom_no_contact_CallbackFunctionPointer(Mock.custom_no_contact_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void custom_no_contact_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_no_contact_CALL_INSTANCE));
  CMOCK_custom_no_contact_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_no_contact_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_no_contact_CallInstance = CMock_Guts_MemChain(Mock.custom_no_contact_CallInstance, cmock_guts_index);
  Mock.custom_no_contact_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.custom_no_contact_IgnoreBool = (char)1;
}

void custom_no_contact_CMockStopIgnore(void)
{
  if(Mock.custom_no_contact_IgnoreBool)
    Mock.custom_no_contact_CallInstance = CMock_Guts_MemNext(Mock.custom_no_contact_CallInstance);
  Mock.custom_no_contact_IgnoreBool = (char)0;
}

void custom_no_contact_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_no_contact_CALL_INSTANCE));
  CMOCK_custom_no_contact_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_no_contact_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_no_contact_CallInstance = CMock_Guts_MemChain(Mock.custom_no_contact_CallInstance, cmock_guts_index);
  Mock.custom_no_contact_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void custom_no_contact_AddCallback(CMOCK_custom_no_contact_CALLBACK Callback)
{
  Mock.custom_no_contact_IgnoreBool = (char)0;
  Mock.custom_no_contact_CallbackBool = (char)1;
  Mock.custom_no_contact_CallbackFunctionPointer = Callback;
}

void custom_no_contact_Stub(CMOCK_custom_no_contact_CALLBACK Callback)
{
  Mock.custom_no_contact_IgnoreBool = (char)0;
  Mock.custom_no_contact_CallbackBool = (char)0;
  Mock.custom_no_contact_CallbackFunctionPointer = Callback;
}

int custom_activation(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_custom_activation_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_custom_activation);
  cmock_call_instance = (CMOCK_custom_activation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.custom_activation_CallInstance);
  Mock.custom_activation_CallInstance = CMock_Guts_MemNext(Mock.custom_activation_CallInstance);
  if (Mock.custom_activation_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.custom_activation_FinalReturn;
    Mock.custom_activation_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.custom_activation_CallbackBool &&
      Mock.custom_activation_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.custom_activation_CallbackFunctionPointer(Mock.custom_activation_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.custom_activation_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.custom_activation_CallbackFunctionPointer(Mock.custom_activation_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void custom_activation_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_activation_CALL_INSTANCE));
  CMOCK_custom_activation_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_activation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_activation_CallInstance = CMock_Guts_MemChain(Mock.custom_activation_CallInstance, cmock_guts_index);
  Mock.custom_activation_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.custom_activation_IgnoreBool = (char)1;
}

void custom_activation_CMockStopIgnore(void)
{
  if(Mock.custom_activation_IgnoreBool)
    Mock.custom_activation_CallInstance = CMock_Guts_MemNext(Mock.custom_activation_CallInstance);
  Mock.custom_activation_IgnoreBool = (char)0;
}

void custom_activation_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_activation_CALL_INSTANCE));
  CMOCK_custom_activation_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_activation_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_activation_CallInstance = CMock_Guts_MemChain(Mock.custom_activation_CallInstance, cmock_guts_index);
  Mock.custom_activation_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void custom_activation_AddCallback(CMOCK_custom_activation_CALLBACK Callback)
{
  Mock.custom_activation_IgnoreBool = (char)0;
  Mock.custom_activation_CallbackBool = (char)1;
  Mock.custom_activation_CallbackFunctionPointer = Callback;
}

void custom_activation_Stub(CMOCK_custom_activation_CALLBACK Callback)
{
  Mock.custom_activation_IgnoreBool = (char)0;
  Mock.custom_activation_CallbackBool = (char)0;
  Mock.custom_activation_CallbackFunctionPointer = Callback;
}

int custom_get_time(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_custom_get_time_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_custom_get_time);
  cmock_call_instance = (CMOCK_custom_get_time_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.custom_get_time_CallInstance);
  Mock.custom_get_time_CallInstance = CMock_Guts_MemNext(Mock.custom_get_time_CallInstance);
  if (Mock.custom_get_time_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.custom_get_time_FinalReturn;
    Mock.custom_get_time_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.custom_get_time_CallbackBool &&
      Mock.custom_get_time_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.custom_get_time_CallbackFunctionPointer(Mock.custom_get_time_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.custom_get_time_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.custom_get_time_CallbackFunctionPointer(Mock.custom_get_time_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void custom_get_time_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_get_time_CALL_INSTANCE));
  CMOCK_custom_get_time_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_get_time_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_get_time_CallInstance = CMock_Guts_MemChain(Mock.custom_get_time_CallInstance, cmock_guts_index);
  Mock.custom_get_time_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.custom_get_time_IgnoreBool = (char)1;
}

void custom_get_time_CMockStopIgnore(void)
{
  if(Mock.custom_get_time_IgnoreBool)
    Mock.custom_get_time_CallInstance = CMock_Guts_MemNext(Mock.custom_get_time_CallInstance);
  Mock.custom_get_time_IgnoreBool = (char)0;
}

void custom_get_time_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_custom_get_time_CALL_INSTANCE));
  CMOCK_custom_get_time_CALL_INSTANCE* cmock_call_instance = (CMOCK_custom_get_time_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.custom_get_time_CallInstance = CMock_Guts_MemChain(Mock.custom_get_time_CallInstance, cmock_guts_index);
  Mock.custom_get_time_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void custom_get_time_AddCallback(CMOCK_custom_get_time_CALLBACK Callback)
{
  Mock.custom_get_time_IgnoreBool = (char)0;
  Mock.custom_get_time_CallbackBool = (char)1;
  Mock.custom_get_time_CallbackFunctionPointer = Callback;
}

void custom_get_time_Stub(CMOCK_custom_get_time_CALLBACK Callback)
{
  Mock.custom_get_time_IgnoreBool = (char)0;
  Mock.custom_get_time_CallbackBool = (char)0;
  Mock.custom_get_time_CallbackFunctionPointer = Callback;
}
