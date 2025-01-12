/*!
 * @file stack.c
 *
 * @brief This file contains a generic stack implementation using
 *          a singly linked list.
 *
 *          The stack will contain references to any type of data,
 *              but will not be responsible for allocation or
 *              deallocation of referenced data.
 *
 *          Functions supported are as follows:
 *
 *              - stack_create
 *              - stack_destroy
 *              - stack_push
 *              - stack_pop
 */

#include "stack.h"

/*!
 * @brief This function instantiates a new empty stack.
 *
 * @return Pointer to new stack context. NULL on error.
 */
stack_t *
stack_create (void)
{
    stack_t * p_stack = calloc(1, sizeof(stack_t));
    if (NULL == p_stack)
    {
        goto EXIT;
    }
    p_stack->p_head = NULL;
    p_stack->p_tail = NULL;
    p_stack->size = 0;
    
    EXIT:
        return p_stack;
}

/*!
 * @brief This function destroys a stack context.
 *
 *          This will not deallocate any data referenced by the stack.
 *              That responsiblility is left to the client since it
 *              is impossible to know if the data referenced is
 *              stack or heap allocated.
 *
 * @param[in/out] p_stack The stack context.
 *
 * @return No return value expected.
 */
void
stack_destroy (stack_t * p_stack)
{
    if ((NULL == p_stack) ||
        (NULL == p_stack->p_head))
    {
        goto EXIT;
    }
    
    // Free each node in the stack.
    stack_node_t * p_curr = p_stack->p_head;
    stack_node_t * p_next = NULL;
    
    while (NULL != p_curr)
    {
        p_next = p_curr->p_next;
        free(p_curr);
        p_curr = p_next;
    }
    
    EXIT:
        if (NULL != p_stack)
        {
            free(p_stack);
            p_stack = NULL;
        }
        return;
}

/*!
 * @brief This function pushes data onto the stack.
 *
 * @param[in/out] p_stack The stack context.
 * @param[in/out] p_data The data to push.
 *
 * @return 0 on success, -1 on error.
 */
int
stack_push (stack_t * p_stack, void * p_data)
{
    int status = -1;
    if ((NULL == p_stack) ||
        (NULL == p_data))
    {
        goto EXIT;
    }
    
    // Create a new node.
    stack_node_t * p_new = calloc(1, sizeof(stack_node_t));
    if (NULL == p_new)
    {
        goto EXIT;
    }
    p_new->p_data = p_data;
    p_new->p_next = NULL;
    
    // Push new node.
    if (NULL == p_stack->p_head)
    {
        p_stack->p_head = p_new;
        p_stack->p_tail = p_new;
    }
    else
    {
        p_new->p_next = p_stack->p_head;
        p_stack->p_head = p_new;
    }
    p_stack->size++;
    
    status = 0;
    
    EXIT:
        return status;
}

/*!
 * @brief This function pops the last node in the stack
 *          (The most recently pushed node).
 *
 * @param[in/out] p_stack The stack context.
 *
 * @return Pointer to the data held in the first node of the stack.
 *          NULL on error or empty stack.
 */
void *
stack_pop (stack_t * p_stack)
{
    void * p_result = NULL;
    if ((NULL == p_stack) ||
        (NULL == p_stack->p_head))
    {
        goto EXIT;
    }
    
    stack_node_t * p_next = p_stack->p_head->p_next;
    p_result = p_stack->p_head->p_data;
    free(p_stack->p_head);
    p_stack->p_head = p_next;
    
    if (NULL == p_stack->p_head)
    {
        p_stack->p_tail = NULL;
    }
    p_stack->size--;
    
    EXIT:
        return p_result;
}

/***   end of file   ***/
