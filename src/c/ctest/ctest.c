/*!
 * @file src/c/ctest/ctest.c
 *
 * @brief This library provides a unit test framework for C files.
 */

#include "ctest.h"

C_BOOL
C_assertImpl (C_BOOL b_value,
              unsigned int line,
              const char * p_strcond,
              const char * p_strfile,
              const char * p_strfunc,
              C_BOOL b_fatal)
{
    if ((NULL == p_strcond) ||
        (NULL == p_strfile))
    {
        goto EXIT;
    }

    EXIT:
        return b_value;
}