#include "unity.h"

#define TEST_CASE(...)

#include "fsm.h"
#include "mock_test_fsm.h"

#include <stdlib.h>

/**
 * @file test_fsm_legacy.c
 * @author 
 * @author 
 * @brief Tests for existing fsm module
 * @version 0.1
 * @date 2024-04-09
 * 
 */

/**
 * @brief Stub or Callback for fsm_malloc that calls real malloc. 
 * 
 * @param[in] s Amount of bytes to allocate
 * @param[in] n Amount of calls to this function
 * 
 * @return pointer to allocated memory if success; NULL if fails
 * 
 */
static void* cb_malloc(size_t s, int n) {
    return malloc(s);
}

/**
 * @brief Stub or Callback for fsm_free that calls real free. 
 * 
 * @param[in] p Pointer to allocated memory to free
 * @param[in] n Amount of calls to this function
 * 
 */
static void cb_free(void* p, int n) {
    return free(p);
}

void setUp(void)
{
}

void tearDown(void)
{
}
/**
 * @brief Table with 129 max transitions
 * 
 */
fsm_trans_t big_tt[] = {
    {0, is_true, 1, NULL},
    {1, is_true, 2, NULL},  
    {2, is_true, 3, NULL},
    {3, is_true, 4, NULL},
    {4, is_true, 5, NULL},
    {5, is_true, 6, NULL},
    {6, is_true, 7, NULL},
    {7, is_true, 8, NULL},
    {8, is_true, 9, NULL},
    {9, is_true, 10, NULL},
    {10, is_true, 11, NULL},
    {11, is_true, 12, NULL},
    {12, is_true, 13, NULL},
    {13, is_true, 14, NULL},
    {14, is_true, 15, NULL},
    {15, is_true, 16, NULL},
    {16, is_true, 17, NULL},
    {17, is_true, 18, NULL},
    {18, is_true, 19, NULL},
    {19, is_true, 20, NULL},
    {20, is_true, 21, NULL},
    {21, is_true, 22, NULL},
    {22, is_true, 23, NULL},
    {23, is_true, 24, NULL},
    {24, is_true, 25, NULL},
    {25, is_true, 26, NULL},
    {26, is_true, 27, NULL},
    {27, is_true, 28, NULL},
    {28, is_true, 29, NULL},
    {29, is_true, 30, NULL},
    {30, is_true, 31, NULL},
    {31, is_true, 32, NULL},
    {32, is_true, 33, NULL},
    {33, is_true, 34, NULL},
    {34, is_true, 35, NULL},
    {35, is_true, 36, NULL},
    {36, is_true, 37, NULL},
    {37, is_true, 38, NULL},
    {38, is_true, 39, NULL},
    {39, is_true, 40, NULL},
    {40, is_true, 41, NULL},
    {41, is_true, 42, NULL},
    {42, is_true, 43, NULL},
    {43, is_true, 44, NULL},
    {44, is_true, 45, NULL},
    {45, is_true, 46, NULL},
    {46, is_true, 47, NULL},
    {47, is_true, 48, NULL},
    {48, is_true, 49, NULL},
    {49, is_true, 50, NULL},
    {50, is_true, 51, NULL},
    {51, is_true, 52, NULL},
    {52, is_true, 53, NULL},
    {53, is_true, 54, NULL},
    {54, is_true, 55, NULL},
    {55, is_true, 56, NULL},
    {56, is_true, 57, NULL},
    {57, is_true, 58, NULL},
    {58, is_true, 59, NULL},
    {59, is_true, 60, NULL},
    {60, is_true, 61, NULL},
    {61, is_true, 62, NULL},
    {62, is_true, 63, NULL},
    {63, is_true, 64, NULL},
    {64, is_true, 65, NULL},
    {65, is_true, 66, NULL},
    {66, is_true, 67, NULL},
    {67, is_true, 68, NULL},
    {68, is_true, 69, NULL},
    {69, is_true, 70, NULL},
    {70, is_true, 71, NULL},
    {71, is_true, 72, NULL},
    {72, is_true, 73, NULL},
    {73, is_true, 74, NULL},
    {74, is_true, 75, NULL},
    {75, is_true, 76, NULL},
    {76, is_true, 77, NULL},
    {77, is_true, 78, NULL},
    {78, is_true, 79, NULL},
    {79, is_true, 80, NULL},
    {80, is_true, 81, NULL},
    {81, is_true, 82, NULL},
    {82, is_true, 83, NULL},
    {83, is_true, 84, NULL},
    {84, is_true, 85, NULL},
    {85, is_true, 86, NULL},
    {86, is_true, 87, NULL},
    {87, is_true, 88, NULL},
    {88, is_true, 89, NULL},
    {89, is_true, 90, NULL},
    {90, is_true, 91, NULL},
    {91, is_true, 92, NULL},
    {92, is_true, 93, NULL},
    {93, is_true, 94, NULL},
    {94, is_true, 95, NULL},
    {95, is_true, 96, NULL},
    {96, is_true, 97, NULL},
    {97, is_true, 98, NULL},
    {98, is_true ,99 ,NULL},  
    {99, is_true ,100 ,NULL},  
    {100, is_true ,101 ,NULL},  
    {101, is_true ,102 ,NULL},  
    {102, is_true ,103 ,NULL},  
    {103, is_true ,104 ,NULL},  
    {104, is_true ,105 ,NULL},  
    {105, is_true ,106 ,NULL},  
    {106, is_true ,107 ,NULL},  
    {107, is_true ,108 ,NULL},  
    {108, is_true ,109 ,NULL},  
    {109, is_true ,110 ,NULL},  
    {110, is_true ,111 ,NULL},  
    {111, is_true ,112 ,NULL},  
    {112, is_true ,113 ,NULL},  
    {113, is_true ,114 ,NULL},  
    {114, is_true ,115 ,NULL},  
    {115, is_true ,116 ,NULL},  
    {116, is_true ,117 ,NULL},  
    {117, is_true ,118 ,NULL},  
    {118, is_true ,119 ,NULL},  
    {119, is_true ,120 ,NULL},  
    {120, is_true ,121 ,NULL},  
    {121, is_true ,122 ,NULL},  
    {122, is_true ,123 ,NULL},  
    {123, is_true ,124 ,NULL},  
    {124, is_true ,125 ,NULL},  
    {125, is_true ,126 ,NULL},  
    {126, is_true ,127 ,NULL},  
    {127, is_true ,128 ,NULL},  
    {128, is_true ,129 ,NULL}, 
    {-1, NULL, -1, NULL}
};

/**
 * @brief Comprueba que la funcion de fsm_new devuelve NULL 
 *        y no llama a fsm_malloc si la tabla de transiciones es NULL 
 */
void test_fsm_new_nullWhenNullTransition(void)
{
    fsm_t *f = (fsm_t*)1;

    f = fsm_new(NULL);

    TEST_ASSERT_EQUAL (NULL, f);
}

/**
 * @brief Comprueba que fsm_init devuelve el numero de transiciones válidas en la tabla de transiciones
 *
 */
void test_fsm_init_returnsValidTransitions(void)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {1, is_true, 0, NULL},  
        {-1, NULL, -1, NULL}
    };

    int expected_transitions = 2;
    fsm_t f;
    int transitions = fsm_init(&f, tt);
    TEST_ASSERT_EQUAL(expected_transitions, transitions);
}

/**
 * @brief Si hay más de FSM_MAX_TRANSITIONS transiciones, la función fsm_init devuelve 0.
 * 
 */
void test_fsm_init_returnsZeroWhenMaxTransitions(void)
{
    int expected_transitions = 0;
    fsm_t f;
    int transitions = fsm_init(&f, big_tt);
    TEST_ASSERT_EQUAL(expected_transitions, transitions);
}

/**
 * @brief Comprueba que una función de guarda NULL se interpreta como si devolviese ¨true¨. Usa Stub para fsm_malloc y luego libera la memoria con free
 * 
 */
void test_fsm_transitionWhenGuardIsNull(void){
    int STATE0 = 0;
    int STATE1 = 1;
    fsm_trans_t tt[] = {
        {STATE0, NULL, STATE1, NULL},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_Stub(cb_malloc);
    fsm_t *f = fsm_new(tt);
    fsm_fire(f);
    int state = fsm_get_state(f);
    TEST_ASSERT_EQUAL(STATE1, state);
    free(f);
}

/**
 * @brief Comprueba que cuando no hay transiciones disponibles, fsm_fire devuelve -1. Usa Stub para fsm_malloc y luego libera la memoria con free
 * 
 */
void test_fsm_fire_returnsMinusOneWhenNoTransitionsAvailable(void){
    int STATE0 = 0;
    int STATE1 = 1;
    fsm_trans_t tt[] = {
        {STATE0, NULL, STATE1, NULL},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_Stub(cb_malloc);
    fsm_t *f = fsm_new(tt);
    fsm_fire(f);

    int ret = fsm_fire(f);
    TEST_ASSERT_EQUAL(-1, ret);

    free(f);
}

/**
 * @brief Comprueba que cuando hay transiciones disponibles, fsm_fire devuelve 0 si la funcion de guarda no se cumple y devuelve 1 si esta devuelve true y se realiza la transicion.
 * Usa Stub para fsm_malloc y luego libera la memoria con free
 */
TEST_CASE(0)
TEST_CASE(1)
void test_fsm_fire_returnsWithTransitionsAvailable(int expected){
    int STATE0 = 0;
    int STATE1 = 1;
    fsm_trans_t tt[] = {
        {STATE0, is_true, STATE1, NULL},
        {-1, NULL, -1, NULL}
    };

    if(expected == 0){
        is_true_IgnoreAndReturn(0);
    }else{
        is_true_IgnoreAndReturn(1);
    }

    fsm_malloc_Stub(cb_malloc);
    fsm_t *f = fsm_new(tt);

    int ret = fsm_fire(f);

    TEST_ASSERT_EQUAL(expected, ret);

    free(f);
}

/** 
* @brief Comprueba que cuando se llama a fsm_new con una tabla de transiciones que excede el maximo, esta no llama a malloc. 
*/
void test_fsm_new_doesNotCallMallocWhenMoreThanMaxTransitions(void){

    fsm_t *f = fsm_new(big_tt);
    TEST_ASSERT_EQUAL(NULL, f);
}

/**
 * @brief La máquina de estados devuelve NULL
 *        y no llama a fsm_malloc si el estado de origen
 *        de la primera transición es -1 (fin de la tabla)
 */
void test_fsm_nullWhenFirstOrigStateIsMinusOne (void) {
    fsm_trans_t tt[] = {{-1, is_true, 1, do_nothing}};
    fsm_t *f = (fsm_t*)1;
    f = fsm_new(tt);
 
    TEST_ASSERT_EQUAL (f, NULL);
}

/**
 * @brief La máquina de estados devuelve NULL y no llama a fsm_malloc si el estado de destino de la primera transición es -1 (fin de la tabla)
 * 
 */
void test_fsm_nullWhenFirstDstStateIsMinusOne (void) {
    fsm_trans_t tt[] = {{1, is_true, -1, do_nothing}};
    fsm_t *f = (fsm_t*)1;
    f = fsm_new(tt);
   
    TEST_ASSERT_EQUAL (f, NULL);
}

/**
 * @brief Devuelve puntero no NULL y llama a fsm_malloc (usa Callback a cb_mallock y fsm_malloc_ExpectXXX) al crear la maquina de estados con una transición válida
 *        con función de actualización (salida) NULL o no NULL.
 *        Hay que liberar la memoria al final llamando a free
 * 
 */
TEST_CASE(NULL)
TEST_CASE(do_nothing)
void test_fsm_new_nonNullWhenOneValidTransitionCondition(fsm_output_func_t out)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, out},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_AddCallback(cb_malloc);
    fsm_malloc_ExpectAnyArgsAndReturn((void*)1);
    fsm_t *f = fsm_new(tt); 
    TEST_ASSERT_NOT_NULL(f);
     
    free(f);
}


/**
 * @brief Estado inicial corresponde al estado de entrada de la primera transición de la lista al crear una maquina de estados y es valido.
 *        Usa Stub para fsm_malloc y luego libera la memoria con free
 */
void test_fsm_new_fsmGetStateReturnsOrigStateOfFirstTransitionAfterInit(void)
{
    int STATE0 = 123;
    int STATE1 = 321;
    fsm_trans_t tt[] = {
        {STATE0, is_true, STATE1, do_nothing},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_Stub(cb_malloc);
    fsm_t *f = fsm_new(tt);
    int state = fsm_get_state(f);
    TEST_ASSERT_EQUAL(STATE0, state);

    free(f);
}

/**
 * @brief La maquina de estado no transiciona si la funcion devuelve 0
 * 
 */
void test_fsm_fire_isTrueReturnsFalseMeansDoNothingIsNotCalledAndStateKeepsTheSame(void)
{
    int STATE0 = 123;
    int STATE1 = 321;
    fsm_trans_t tt[] = {
        {STATE0, is_true, STATE1, do_nothing},
        {-1, NULL, -1, NULL}
    };
    is_true_IgnoreAndReturn(0);
    fsm_malloc_Stub(cb_malloc);
    fsm_t *f = fsm_new(tt);
    int state = fsm_get_state(f);
    TEST_ASSERT_EQUAL(STATE0, state);

    free(f);
}

/**
 * @brief Comprueba que el puntero pasado a fsm_fire es pasado a la función de guarda cuando se comprueba una transición
 * 
 */
void test_fsm_fire_checkFunctionCalledWithFsmPointerFromFsmFire(void)
{

    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {-1, NULL, -1, NULL}
    };

    fsm_malloc_Stub(cb_malloc);

    fsm_t *f = fsm_new(tt);
    is_true_ExpectAndReturn(f, 1);
    fsm_fire(f);

    free(f);
}

/** 
 * @brief Comprueba que el fsm_fire funciona y tiene el estado correcto cuando la transición devuelve true (cambia) y cuando devuelve false (mantiene)
 * 
 */
TEST_CASE(false, 0)
TEST_CASE(true, 1)
void test_fsm_fire_checkFunctionIsCalledAndResultIsImportantForTransition(bool returnValue, int expectedState)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {-1, NULL, -1, NULL}
    };
    fsm_t f;
    fsm_init(&f, tt);
    is_true_IgnoreAndReturn(returnValue);
    fsm_fire(&f);
    int state = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(expectedState, state);
}


/**
 * @brief La creación de una máquina de estados devuelve NULL si la reserva de memoria falla.
 *        Usa el Mock llamando a fsm_malloc_ExpectXXX sin Stub ni Callback.
 *
 */
void test_fsm_new_nullWhenFsmMallocReturnsNull(void)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {1, is_true, 0, NULL},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_ExpectAnyArgsAndReturn(NULL);
    fsm_t *f = fsm_new(tt);
    TEST_ASSERT_EQUAL(NULL, f);

    free(f);
}

/**
 * @brief Llamar a fsm_destroy provoca una llamada a fsm_free
 *        Usa el Mock llamando a fsm_free_Expect sin Stub ni Callback
 *
 */
void test_fsm_destroy_callsFsmFree(void)
{
    fsm_t *f = (fsm_t*)1;
    fsm_free_ExpectAnyArgs();
    fsm_destroy(f);
}

/**
 * @brief Comprueba que solo se llame a la función de guarda que toca según el estado actual
 * 
 */
void test_fsm_fire_callsFirstIsTrueFromState0AndThenIsTrue2FromState1(void)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {1, is_true2, 0, NULL},  
        {-1, NULL, -1, NULL}
    };
    fsm_t f;
    int res;
    fsm_init(&f, tt);
    res = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(0, res);
    is_true_ExpectAndReturn(&f, 1);
    fsm_fire(&f);
    res = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(1, res);
    is_true2_ExpectAndReturn(&f, 1);
    fsm_fire(&f);
    res = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(0, res);
}

/**
 * @brief Comprueba que se pueden crear dos instancias de máquinas de estados simultánteas y son punteros distintos.
 *        Usa Stub para fsm_malloc y luego libera la memoria con free
 *
 */
void test_fsm_new_calledTwiceWithSameValidDataCreatesDifferentInstancePointer(void)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, NULL},
        {-1, NULL, -1, NULL}
    };
    fsm_malloc_Stub(cb_malloc);
    fsm_t *f1 = fsm_new(tt);
    fsm_t *f2 = fsm_new(tt);

    TEST_ASSERT_NOT_EQUAL(f1, f2);

    free(f1);
    free(f2);
}

/**
 * @brief Comprueba que si la tabla de transiciones es valida y tiene función de salida, esta se ejecuta.
 *
 */
void test_fsm_fire_outFunctionCalled(void)
{
    fsm_trans_t tt[] = {
        {0, is_true, 1, do_nothing},
        {-1, NULL, -1, NULL}
    };
    
    fsm_t f;
    fsm_init(&f, tt);
    do_nothing_ExpectAnyArgs();
    is_true_IgnoreAndReturn(1);
    fsm_fire(&f);
}

/**
 * @brief La máquina de estados devuelve NULL si la tabla de transiciones es NULL
 */
void test_fsm_NotModifiedWhenTTnull (void) {
    fsm_t f;
    int STATE0 = 123;
    fsm_set_state(&f, STATE0);
    int res = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(STATE0, res);

    fsm_init(&f, NULL);
    res = fsm_get_state(&f);
    TEST_ASSERT_EQUAL(STATE0, res);
}

/**
 * @brief La máquina de estados devuelve NULL y no llama a fsm_malloc si la función de comprobación de la primera transición es NULL (fin de la tabla)
 * 
 */
void test_fsm_nullWhenFirstCheckFunctionIsNull (void) {
    fsm_trans_t tt[] = {{-1, NULL, -1, NULL}};
    fsm_t *f = (fsm_t*)1;
    f = fsm_new(tt);
   
    TEST_ASSERT_EQUAL (f, NULL);
}