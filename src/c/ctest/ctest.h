/*!
 * @file src/c/ctest/ctest.h
 *
 * @brief This library provides a unit test framework for C files.
 */

#ifndef _SRC_C_CTEST_CTEST_H
#define _SRC_C_CTEST_CTEST_H

#include <stdlib.h>

#ifndef C_BOOL
    /*** Boolean type for ctest use. ***/
    #define C_BOOL int
#endif

#ifndef C_TRUE
    /*** Boolean true for ctest use. ***/
    #define C_TRUE 1
#endif

#ifndef C_FALSE
    /*** Boolean false for ctest use. ***/
    #define C_FALSE 0
#endif

/*!
 * @brief Assertion function. All C_ASSERT* functions simplify to a call
 *          to this function.
 *
 * @param b_value Value of the assertion.
 * @param line The line number of the assert.
 * @param p_strcond The string condition of logical test.
 * @param p_strfile The name of the source file of logical test.
 * @param p_strfunc The name of the function of logical test.
 * @param b_fatal Should the test abort.
 *
 * @return Returns value of assertion (b_value).
 */
C_BOOL
C_assertImpl (C_BOOL b_value,
              unsigned int line,
              const char * p_strcond,
              const char * p_strfile,
              const char * p_strfunc,
              C_BOOL b_fatal);

/*!
 * @brief Simple assertion.
 */
#define C_ASSERT(value) \
    C_assertImpl((value), __LINE__, #value, __FILE__, "", C_FALSE);

#endif // _SRC_C_CTEST_CTEST_H

/***   end of file   ***/
