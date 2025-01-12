/*!
 * @project C/Threadpool
 *
 * @desc This project is a generic threadpool implementation.
 *
 *          The threadpool is designed to create a set number of threads
 *              upon instantiation, and maintains a queue of jobs
 *              that are passed off to any available threads.
 *
 *          When the threadpool is destroyed, threads will be allowed
 *              to finish out any work on the job queue, then be
 *              joined to the main thread for destruction.
 */

#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <unistd.h>

#include "src/c/threadpool/threadpool.h"

#define NUM_THREADS 3

void
calc_double (_Atomic bool * pb_shutdown, void * p_arg)
{
    int * p_i = (int *) p_arg;
    printf("%d * 2 = %d\n", *p_i, (*p_i) * 2);
    sleep(1);
    return;
}

void sleep_inf (_Atomic bool * pb_shutdown, void * p_arg)
{
    while (false == *pb_shutdown)
    {
        printf("SLEEPY\n");
        sleep(1);
    }
    printf("AWAKE!\n");
    return;
}

int
main ()
{
    // Create threadpool.
    threadpool_t * p_tp = threadpool_create(NUM_THREADS);
    if (NULL == p_tp)
    {
        printf("create\n");
        return 1;
    }
    
    // Enqueue jobs.
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    for (size_t i = 0; i < 10; ++i)
    {
        if (-1 == threadpool_enq(p_tp, (job_f) calc_double, nums + i))
        {
            printf("enq\n");
            return 1;
        }
    }
    
    for (size_t i = 0; i < 10; ++i)
    {
        if (-1 == threadpool_enq(p_tp, (job_f) sleep_inf, NULL))
        {
            printf("enq\n");
            return 1;
        }
    }
    
    sleep(5);
    
    // Destroy the threadpool.
    if (-1 == threadpool_destroy(p_tp))
    {
        printf("destroy\n");
        return 1;
    }
    p_tp = NULL;
    
    printf("success\n");
    return 0;
}

/***   end of file   ***/
