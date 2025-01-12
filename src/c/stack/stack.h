/*!
 * @file stack.h
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

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

/*!
 * @brief This datatype defines a node for the linked list.
 *
 * @param p_data Pointer to the referenced data.
 * @param p_next Pointer to the next node in the stack.
 */
typedef struct _stack_node stack_node_t;
struct _stack_node
{
    void * p_data;
    stack_node_t * p_next;
};

/*!
 * @brief This datatype defines a stack context.
 *
 * @param p_head The first node in the stack.
 * @param p_tail The last node in the stack.
 * @param size The number of nodes in the stack.
 */
typedef struct _stack
{
    stack_node_t * p_head;
    stack_node_t * p_tail;
    size_t size;
} stack_t;

/*!
 * @brief This function instantiates a new stack stack.
 *
 * @return Pointer to new stack context. NULL on error.
 */
stack_t *
stack_create (void);

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
stack_destroy (stack_t * p_stack);

/*!
 * @brief This function pushes data onto the stack.
 *
 * @param[in/out] p_stack The stack context.
 * @param[in/out] p_data The data to push.
 *
 * @return 0 on success, -1 on error.
 */
int
stack_push (stack_t * p_stack, void * p_data);

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
stack_pop (stack_t * p_stack);

#endif // STACK_H

/***   end of file   ***/
