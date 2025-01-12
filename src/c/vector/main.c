/*!
 * @project C/DSA/Vector
 *
 * @desc This project is a generic vector implementation.
 *
 *          The vector is a contiguous, dynamic array of references
 *              to data. It provides O(1) random access.
 *
 *          Reallocations of memory occur automatically when the
 *              number of elements in the vector exceed the allocated
 *              space.
 */

#include <stdio.h>

#include "vector.h"

void
display (vector_t * p_vector)
{
    if (NULL == p_vector)
    {
        goto EXIT;
    }
    
    printf("[");
    for (size_t i = 0; i < p_vector->size; ++i)
    {
        int * p_i = p_vector->pp_data[i];
        if (NULL == p_i)
        {
            goto EXIT;
        }
        printf("%d", *p_i);
        if (i + 1 < p_vector->size)
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
    // Create a vector context.
    vector_t * p_v = vector_create();
    if (NULL == p_v)
    {
        printf("create\n");
        return 1;
    }
    
    // Reserve space on the vector.
    if (-1 == vector_reserve(p_v, 3))
    {
        printf("reserve\n");
        return 1;
    }
    
    // Display the vector.
    display(p_v);
    
    // Push elements on the back of the vector.
    int nums[5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i)
    {
        if (-1 == vector_push_back(p_v, nums + i))
        {
            printf("push_back\n");
            return 1;
        }
    }
    
    // Display the vector.
    display(p_v);
    
    // Push an element to the front of the vector.
    int n = 0;
    if (-1 == vector_push_front(p_v, &n))
    {
        printf("push_front\n");
        return 1;
    }
    
    // Display the vector.
    display(p_v);
    
    // Pop the last element of the vector.
    int * p_i = vector_pop_back(p_v);
    if (NULL == p_i)
    {
        printf("pop_back\n");
        return 1;
    }
    printf("POPPED: %d\n", *p_i);
    
    // Pop the first element of the vector.
    p_i = vector_pop_front(p_v);
    if (NULL == p_i)
    {
        printf("pop_front\n");
        return 1;
    }
    printf("POPPED: %d\n", *p_i);
    
    // Display the vector.
    display(p_v);
    
    // Using the vector_at function for indexing, loop through the vector.
    for (size_t idx = 0; idx < p_v->size; ++idx)
    {
        p_i = vector_at(p_v, idx);
        if (NULL == p_i)
        {
            printf("at\n");
            return 1;
        }
        printf("AT p_v[%lu]: %d\n", idx, *p_i);
    }
    
    // Destroy the vector context.
    vector_destroy(p_v);
    
    printf("success\n");
    return 0;
}

/***   end of file   ***/
