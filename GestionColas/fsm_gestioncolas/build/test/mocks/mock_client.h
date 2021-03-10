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




#define custom_solicitud_cola_IgnoreAndReturn(cmock_retval) custom_solicitud_cola_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void custom_solicitud_cola_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define custom_solicitud_cola_StopIgnore() custom_solicitud_cola_CMockStopIgnore()
void custom_solicitud_cola_CMockStopIgnore(void);
#define custom_solicitud_cola_ExpectAndReturn(cmock_retval) custom_solicitud_cola_CMockExpectAndReturn(__LINE__, cmock_retval)
void custom_solicitud_cola_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_custom_solicitud_cola_CALLBACK)(int cmock_num_calls);
void custom_solicitud_cola_AddCallback(CMOCK_custom_solicitud_cola_CALLBACK Callback);
void custom_solicitud_cola_Stub(CMOCK_custom_solicitud_cola_CALLBACK Callback);
#define custom_solicitud_cola_StubWithCallback custom_solicitud_cola_Stub
#define custom_terminado_IgnoreAndReturn(cmock_retval) custom_terminado_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void custom_terminado_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define custom_terminado_StopIgnore() custom_terminado_CMockStopIgnore()
void custom_terminado_CMockStopIgnore(void);
#define custom_terminado_ExpectAndReturn(cmock_retval) custom_terminado_CMockExpectAndReturn(__LINE__, cmock_retval)
void custom_terminado_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
typedef int (* CMOCK_custom_terminado_CALLBACK)(int cmock_num_calls);
void custom_terminado_AddCallback(CMOCK_custom_terminado_CALLBACK Callback);
void custom_terminado_Stub(CMOCK_custom_terminado_CALLBACK Callback);
#define custom_terminado_StubWithCallback custom_terminado_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
