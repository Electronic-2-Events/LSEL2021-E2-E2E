#include "build/temp/_test_fsm_contador.c"
#include "build/test/mocks/mock_client.h"
#include "src/fsm_contador_internal.h"
#include "src/fsm_contador.h"
#include "src/fsm.h"
#include "/usr/local/bundle/gems/ceedling-0.30.0/vendor/unity/src/unity.h"








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



   fsm_contador_init (&f,

                        ((void*)0)

                            ,

                             ((void*)0)

                                 );

   do {if ((memcmp(&zero, &f, sizeof (fsm_contador_t)) !=0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(27)));}} while(0);

}



void test_fsm_contador_fsmNoSolicitud (void)

 {

     fsm_contador_t f;

     fsm_contador_init(&f, 

                          ((void*)0)

                              , 

                                ((void*)0)

                                    );



     do {if ((f.Personas==0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(35)));}} while(0);



 }



 void test_fsm_contador_fsmFireCallsSolicitudWhenContador (void)

 {

     fsm_contador_t f;



     custom_solicitud_CMockExpectAndReturn(43, 1);



     fsm_contador_init (&f, custom_solicitud, 

                                             ((void*)0)

                                                 );

     f.fsm.current_state = CONTADOR;

     fsm_fire((fsm_t*)(&f));



 }



  void test_fsm_contador_fsmFireCallsListoWhenContador (void)

 {

     fsm_contador_t f;



     custom_listo_CMockExpectAndReturn(55, 1);



     fsm_contador_init (&f, 

                           ((void*)0)

                               , custom_listo);

     f.fsm.current_state = CONTADOR;

     fsm_fire((fsm_t*)(&f));



 }



   void test_fsm_contador_fsmFireTransitionWhenSolicitud (void)

 {

     fsm_contador_t f;



     custom_solicitud_CMockExpectAndReturn(67, 1);



     fsm_contador_init (&f, custom_solicitud, 

                                             ((void*)0)

                                                 );

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);



 }



    void test_fsm_contador_fsmFireTransitionWhenSolicitudAndPersonasHasValue (void)

 {

     fsm_contador_t f;



     custom_solicitud_CMockExpectAndReturn(80, 1);



     fsm_contador_init (&f, custom_solicitud, 

                                             ((void*)0)

                                                 );

     f.Personas = 20;



     fsm_fire((fsm_t*)(&f));

     do {if ((f.Personas==21)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(86)));}} while(0);



 }



     void test_fsm_contador_fsmFireTwoTransitionWhenSolicitudAndPersonasHasValue (void)

 {

     fsm_contador_t f;

     fsm_contador_init (&f, custom_solicitud, 

                                             ((void*)0)

                                                 );

     f.Personas = 20;



     custom_solicitud_CMockExpectAndReturn(96, 1);

     fsm_fire((fsm_t*)(&f));

     custom_solicitud_CMockExpectAndReturn(98, 1);

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==22)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));}} while(0);



 }



    void test_fsm_contador_fsmFireTransitionWhenListo (void)

 {

     fsm_contador_t f;



     custom_listo_CMockExpectAndReturn(109, 1);



     fsm_contador_init (&f, 

                           ((void*)0)

                               , custom_listo);

     f.Personas=1;

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(115)));}} while(0);



 }



     void test_fsm_contador_fsmFireTransitionWhenListoAndPersonaHasBiggerValue (void)

 {

     fsm_contador_t f;



     custom_listo_CMockExpectAndReturn(123, 1);



     fsm_contador_init (&f, 

                           ((void*)0)

                               , custom_listo);

     f.Personas=1000;

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==999)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(129)));}} while(0);



 }



     void test_fsm_contador_fsmFireTwoTransitionWhenListoAndPersonasHasBiggerValue (void)

 {

     fsm_contador_t f;

     fsm_contador_init (&f, 

                           ((void*)0)

                               , custom_listo);

     f.Personas = 10000;



     custom_listo_CMockExpectAndReturn(139, 1);

     fsm_fire((fsm_t*)(&f));

     custom_listo_CMockExpectAndReturn(141, 1);

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==9998)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(144)));}} while(0);



 }



     void test_fsm_contador_fsmFireTransitionWhenNoSolicitudAndNoListoAndPersonasHasValue (void)

 {

     fsm_contador_t f;

     fsm_contador_init (&f, custom_solicitud, custom_listo);

     f.Personas = 100;



     custom_solicitud_CMockExpectAndReturn(154, 0);

     custom_listo_CMockExpectAndReturn(155, 0);

     fsm_fire((fsm_t*)(&f));



     do {if ((f.Personas==100)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(158)));}} while(0);

 }
