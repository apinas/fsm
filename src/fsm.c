/**
 * @file fsm.c
 * @brief Library to create Finite State Machines using composition.
 *
 * This library is expected to be used using composition
 * @author Teachers from the Departamento de Ingeniería Electrónica. Original authors: José M. Moya and Pedro J. Malagón. Latest contributor: Román Cárdenas.
 * @date 2023-09-20
 */

/* Includes ------------------------------------------------------------------*/
/* Standard C includes */
#include <stdlib.h>

/* Other includes */
#include "fsm.h"

//GCOVR_EXCL_START
void* __attribute__((weak)) fsm_malloc(size_t s)
{
    return malloc(s);
}
void __attribute__((weak)) fsm_free(void* p)
{
    free(p);
}
//GCOVR_EXCL_STOP

fsm_t *fsm_new(fsm_trans_t *p_tt)
{
    if (p_tt == NULL)
    {
        return NULL;
    }
    if ((p_tt->orig_state == -1) || (p_tt->dest_state == -1))
    {
        return NULL;
    }
    fsm_t *p_fsm = fsm_malloc(sizeof(fsm_t));
    if (p_fsm != NULL)
    {
        fsm_init(p_fsm, p_tt);
    }
    return p_fsm;
}

void fsm_destroy(fsm_t *p_fsm)
{
    fsm_free(p_fsm);
}

int fsm_init(fsm_t *p_fsm, fsm_trans_t *p_tt)
{
    int valid_transitions = 0;
    fsm_trans_t *p_t;
    if (p_tt != NULL)
    {
        p_fsm->p_tt = p_tt;
        p_fsm->current_state = p_tt->orig_state;
        for (p_t = p_tt; p_t->orig_state >= 0; ++p_t)
        {
            if ((p_t->orig_state >= 0)  && (p_t->dest_state >= 0))
            {
                ++valid_transitions;
            }
        }
        if (valid_transitions > FSM_MAX_TRANSITIONS)
        {
            valid_transitions = 0;
        } 
    }
    return valid_transitions;
}

int fsm_get_state(fsm_t *p_fsm)
{
    return p_fsm->current_state;
}

void fsm_set_state(fsm_t *p_fsm, int state)
{
    p_fsm->current_state = state;
}

int fsm_fire(fsm_t *p_fsm)
{
    fsm_trans_t *p_t;
    int transitions_found = 0;
    for (p_t = p_fsm->p_tt; p_t->orig_state >= 0; ++p_t)
    {
        if ((p_fsm->current_state == p_t->orig_state))
        {
            
            if(p_t->in == NULL || p_t->in(p_fsm)){
                p_fsm->current_state = p_t->dest_state;
                if (p_t->out)
                {
                    p_t->out(p_fsm);
                }
                //Transition found and executed, return 1;
                return 1;
            } else {
                //Transitions found but cannot be executed
                transitions_found++;
            }
        }
    }
    if(!transitions_found)
    {
        //No transition found, return -1
        return -1;
    } else {
        //Transitions found, but not executed, return 0
        return 0;
    }
}
