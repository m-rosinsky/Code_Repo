#include <stdio.h>
#include "src/c/queue/queue.h"

void
print_queue (queue_t * p_q)
{
    queue_node_t * p_node = p_q->p_head;

    printf("[");
    while (NULL != p_node)
    {
        printf("%d", * (int *)(p_node->p_data));
        if (NULL != p_node->p_next)
        {
            printf(", ");
        }
        p_node = p_node->p_next;
    }
    printf("]\n");
}

int
main (void)
{
    queue_t * p_q = queue_create();

    int nums[5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i)
    {
        if (-1 == queue_enq(p_q, nums + i))
        {
            printf("enq\n");
            return 1;
        }
    }

    print_queue(p_q);

    queue_destroy(p_q);
    return 0;
}
