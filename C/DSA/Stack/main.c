/*!
 * @project C/DSA/Stack
 *
 * @desc This project is a generic Stack implementation
 *
 *          The Stack should be a singly-linked list that can
 *              hold a reference to any type of data.
 *
 *          Functions supported are as follows:
 *
 *              - stack_create
 *              - stack_destroy
 *              - stack_push
 *              - stack_pop
 */

#include <stdio.h>

#include "stack.h"

void
display (stack_t * p_q)
{
    if (NULL == p_q)
    {
        goto EXIT;
    }
    
    stack_node_t * p_curr = p_q->p_head;
    printf("[");
    while (NULL != p_curr)
    {
        int * p_i = p_curr->p_data;
        if (NULL == p_i)
        {
            goto EXIT;
        }
        printf("%d", *p_i);
        p_curr = p_curr->p_next;
        if (NULL != p_curr)
        {
            printf(", ");
        }
    }
    printf("]\n");
    
    EXIT:
        return;
}

int
main ()
{
    stack_t * p_q = stack_create();
    if (NULL == p_q)
    {
        fprintf(stderr, "create\n");
        return 1;
    }
    
    int nums[5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i)
    {
        if (-1 == stack_push(p_q, nums + i))
        {
            fprintf(stderr, "push\n");
            return 1;
        }
        display(p_q);
    }
    
    int * p_i = stack_pop(p_q);
    while (NULL != p_i)
    {
        printf("POP: %d\n", *p_i);
        display(p_q);
        p_i = stack_pop(p_q);
    }
    
    stack_destroy(p_q);
    printf("success\n");
    return 0;
}

/***   end of file   ***/
