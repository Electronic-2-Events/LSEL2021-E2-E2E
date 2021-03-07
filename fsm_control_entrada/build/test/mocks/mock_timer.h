/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_TIMER_H
#define _MOCK_TIMER_H

#include "unity.h"
#include "timer.h"

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

void mock_timer_Init(void);
void mock_timer_Destroy(void);
void mock_timer_Verify(void);




#define timer_IgnoreAndReturn(cmock_retval) timer_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void timer_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
#define timer_StopIgnore() timer_CMockStopIgnore()
void timer_CMockStopIgnore(void);
#define timer_ExpectAndReturn(cmock_retval) timer_CMockExpectAndReturn(__LINE__, cmock_retval)
void timer_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
typedef uint32_t (* CMOCK_timer_CALLBACK)(int cmock_num_calls);
void timer_AddCallback(CMOCK_timer_CALLBACK Callback);
void timer_Stub(CMOCK_timer_CALLBACK Callback);
#define timer_StubWithCallback timer_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif