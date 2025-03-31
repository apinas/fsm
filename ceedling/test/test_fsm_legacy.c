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
 * @brief Comprueba que la función de inicialización devuelve false si el puntero a la maquina de estado es NULL 
 *
 */
void test_fsm_init_falseWhenNullFsm(void)
{
    TEST_IGNORE();
}

/**
 * @brief Función de inicializacion devuelve false si la tabla de transiciones es nula
 * 
 */
void test_fsm_init_falseWhenNullTransitions(void)
{
    TEST_IGNORE();
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
 * @brief La máquina de estados devuelve NULL y no llama a fsm_malloc si la función de comprobación de la primera transición es NULL (fin de la tabla)
 * 
 */
void test_fsm_nullWhenFirstCheckFunctionIsNull (void) {
    fsm_trans_t tt[] = {{1, NULL, 1, do_nothing}};
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