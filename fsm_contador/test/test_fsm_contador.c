#include <string.h>

#include "unity.h"

#include "fsm.h"
#include "fsm_contador.h"
#include "fsm_contador_internal.h"

#include "mock_client.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_fsm_contador_fsmInitFillsStruct(void)
{
   fsm_contador_t zero;
   fsm_contador_t f;
   bzero(&zero,sizeof(fsm_contador_t));
   bzero(&f,sizeof(fsm_contador_t));

   fsm_contador_init (&f,NULL,NULL);
   TEST_ASSERT(memcmp(&zero, &f, sizeof (fsm_contador_t)) !=0);
}

void test_fsm_contador_fsmNoSolicitud (void)
 {
     fsm_contador_t f;
     fsm_contador_init(&f, NULL, NULL);

     TEST_ASSERT_TRUE(f.Personas==0);

 }

 void test_fsm_contador_fsmFireCallsSolicitudWhenContador (void)
 {
     fsm_contador_t f;
     
     custom_solicitud_ExpectAndReturn(1);

     fsm_contador_init (&f, custom_solicitud, NULL);
     f.fsm.current_state = CONTADOR;
     fsm_fire((fsm_t*)(&f));

 }

  void test_fsm_contador_fsmFireCallsListoWhenContador (void)
 {
     fsm_contador_t f;
     
     custom_listo_ExpectAndReturn(1);

     fsm_contador_init (&f, NULL, custom_listo);
     f.fsm.current_state = CONTADOR;
     fsm_fire((fsm_t*)(&f));

 }

   void test_fsm_contador_fsmFireTransitionWhenSolicitud (void)
 {
     fsm_contador_t f;
    
     custom_solicitud_ExpectAndReturn(1);

     fsm_contador_init (&f, custom_solicitud, NULL);
     fsm_fire((fsm_t*)(&f));
     
     TEST_ASSERT_TRUE(f.Personas==1);

 }

    void test_fsm_contador_fsmFireTransitionWhenSolicitudAndPersonasHasValue (void)
 {
     fsm_contador_t f;
     
     custom_solicitud_ExpectAndReturn(1);

     fsm_contador_init (&f, custom_solicitud, NULL);
     f.Personas = 20;

     fsm_fire((fsm_t*)(&f));
     TEST_ASSERT_TRUE(f.Personas==21);

 }

     void test_fsm_contador_fsmFireTwoTransitionWhenSolicitudAndPersonasHasValue (void)
 {
     fsm_contador_t f;
     fsm_contador_init (&f, custom_solicitud, NULL);
     f.Personas = 20;

     custom_solicitud_ExpectAndReturn(1);
     fsm_fire((fsm_t*)(&f));
     custom_solicitud_ExpectAndReturn(1);
     fsm_fire((fsm_t*)(&f));

     TEST_ASSERT_TRUE(f.Personas==22);

 }

    void test_fsm_contador_fsmFireTransitionWhenListo (void)
 {
     fsm_contador_t f;
    
     custom_listo_ExpectAndReturn(1);

     fsm_contador_init (&f, NULL, custom_listo);
     f.Personas=1; //Ya que para que se haya dado listo, el numero minimo de personas es 1, ya que de ser 0 significaria que no hay cola
     fsm_fire((fsm_t*)(&f));
     
     TEST_ASSERT_TRUE(f.Personas==0);

 }

     void test_fsm_contador_fsmFireTransitionWhenListoAndPersonaHasBiggerValue (void)
 {
     fsm_contador_t f;
    
     custom_listo_ExpectAndReturn(1);

     fsm_contador_init (&f, NULL, custom_listo);
     f.Personas=1000; //Ya que para que se haya dado listo, el numero minimo de personas es 1, ya que de ser 0 significaria que no hay cola
     fsm_fire((fsm_t*)(&f));
     
     TEST_ASSERT_TRUE(f.Personas==999);

 }

     void test_fsm_contador_fsmFireTwoTransitionWhenListoAndPersonasHasBiggerValue (void)
 {
     fsm_contador_t f;
     fsm_contador_init (&f, NULL, custom_listo);
     f.Personas = 10000;

     custom_listo_ExpectAndReturn(1);
     fsm_fire((fsm_t*)(&f));
     custom_listo_ExpectAndReturn(1);
     fsm_fire((fsm_t*)(&f));

     TEST_ASSERT_TRUE(f.Personas==9998);

 }

     void test_fsm_contador_fsmFireTransitionWhenNoSolicitudAndNoListoAndPersonasHasValue (void)
 {
     fsm_contador_t f;
     fsm_contador_init (&f, custom_solicitud, custom_listo);
     f.Personas = 100;

     custom_solicitud_ExpectAndReturn(0);
     custom_listo_ExpectAndReturn(0);
     fsm_fire((fsm_t*)(&f));

     TEST_ASSERT_TRUE(f.Personas==100);
 }

