/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_CLIENT_H
#define _MOCK_CLIENT_H

#include "unity.h"
#include "client.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_client_Init(void);
void mock_client_Destroy(void);
void mock_client_Verify(void);




#define custom_no_contact_IgnoreAndReturn(cmock_retval) custom_no_contact_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void custom_no_contact_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define custom_no_contact_StopIgnore() custom_no_contact_CMockStopIgnore()
void custom_no_contact_CMockStopIgnore(void);
#define custom_no_contact_ExpectAndReturn(cmock_retval) custom_no_contact_CMockExpectAndReturn(__LINE__, cmock_retval)
void custom_no_contact_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_custom_no_contact_CALLBACK)(int cmock_num_calls);
void custom_no_contact_AddCallback(CMOCK_custom_no_contact_CALLBACK Callback);
void custom_no_contact_Stub(CMOCK_custom_no_contact_CALLBACK Callback);
#define custom_no_contact_StubWithCallback custom_no_contact_Stub
#define custom_activation_IgnoreAndReturn(cmock_retval) custom_activation_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void custom_activation_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define custom_activation_StopIgnore() custom_activation_CMockStopIgnore()
void custom_activation_CMockStopIgnore(void);
#define custom_activation_ExpectAndReturn(cmock_retval) custom_activation_CMockExpectAndReturn(__LINE__, cmock_retval)
void custom_activation_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_custom_activation_CALLBACK)(int cmock_num_calls);
void custom_activation_AddCallback(CMOCK_custom_activation_CALLBACK Callback);
void custom_activation_Stub(CMOCK_custom_activation_CALLBACK Callback);
#define custom_activation_StubWithCallback custom_activation_Stub
#define custom_get_time_IgnoreAndReturn(cmock_retval) custom_get_time_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void custom_get_time_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define custom_get_time_StopIgnore() custom_get_time_CMockStopIgnore()
void custom_get_time_CMockStopIgnore(void);
#define custom_get_time_ExpectAndReturn(cmock_retval) custom_get_time_CMockExpectAndReturn(__LINE__, cmock_retval)
void custom_get_time_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_custom_get_time_CALLBACK)(int cmock_num_calls);
void custom_get_time_AddCallback(CMOCK_custom_get_time_CALLBACK Callback);
void custom_get_time_Stub(CMOCK_custom_get_time_CALLBACK Callback);
#define custom_get_time_StubWithCallback custom_get_time_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif