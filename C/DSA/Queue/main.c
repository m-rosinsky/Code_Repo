/*!
 * @project C/DSA/queue
 *
 * @desc This project is a generic Queue implementation.
 *
 *          The Queue should be a singly linked-list that can
 *              hold a reference to any type of data.
 *
 *          Function supported are as follows:
 *
 *              - queue_create
 *              - queue_destroy
 *              - queue_enq
 *              - queue_deq
 */

#include <stdio.h>

#include "queue.h"

void
display (queue_t * p_q)
{
    if (NULL == p_q)
    {
        goto EXIT;
    }
    
    queue_node_t * p_curr = p_q->p_head;
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
    queue_t * p_q = queue_create();
    if (NULL == p_q)
    {
        fprintf(stderr, "create\n");
        return 1;
    }
    
    int nums[5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i)
    {
        if (-1 == queue_enq(p_q, nums + i))
        {
            fprintf(stderr, "enq\n");
            return 1;
        }
        display(p_q);
    }
    
    int * p_i = queue_deq(p_q);
    while (NULL != p_i)
    {
        printf("DEQ: %d\n", *p_i);
        display(p_q);
        p_i = queue_deq(p_q);
    }
    
    queue_destroy(p_q);
    
    printf("success\n");
    return 0;
}

/***   end of file   ***/
