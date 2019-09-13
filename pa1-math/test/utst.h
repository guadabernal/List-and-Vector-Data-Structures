//========================================================================
// UTST
//========================================================================
// A very simple set of macros for unit testing.
//
// Author: Yanghui Ou
// Date  : September 13, 2019
//

#ifndef UTST_H
#define UTST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define COLOR_RED   "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

//------------------------------------------------------------------------
// UTST_ASSERT_TRUE( expr_ )
//------------------------------------------------------------------------
// Checks to see if the expression is true.

#define UTST_ASSERT_TRUE( expr_ ) \
  if ( !(expr_) ) { \
    printf(" - [ " COLOR_RED "FAILED" COLOR_RESET " ] Line %d\n", __LINE__); \
    exit( 1 ); \
  } else { \
    printf(" - [ " COLOR_GREEN "passed" COLOR_RESET " ] Line %d\n", __LINE__); \
  }

//------------------------------------------------------------------------
// UTST_ASSERT_FALSE( expr_ )
//------------------------------------------------------------------------
// Checks to see if the expression is false.

#define UTST_ASSERT_FALSE( expr_ ) \
  if ( (expr_) ) { \
    printf(" - [ " COLOR_RED "FAILED" COLOR_RESET " ] Line %d\n", __LINE__); \
    exit( 1 ); \
  } else { \
    printf(" - [ " COLOR_GREEN "passed" COLOR_RESET " ] Line %d\n", __LINE__); \
  }

//------------------------------------------------------------------------
// UTST_ASSERT_INT_EQ( expr0_, expr1_ )
//------------------------------------------------------------------------
// Checks to see if the two expressions are equal using the != operator.

#define UTST_ASSERT_INT_EQ( expr0_, expr1_ ) \
  if ( (expr0_) != (expr1_) ) { \
    printf(" - [ " COLOR_RED "FAILED" COLOR_RESET " ] Line %d: %d != %d\n", __LINE__, (expr0_), (expr1_)); \
    exit( 1 ); \
  } else { \
    printf(" - [ " COLOR_GREEN "passed" COLOR_RESET " ] Line %d: %d == %d\n", __LINE__, (expr0_), (expr1_)); \
  }

//------------------------------------------------------------------------
// UTST_ASSERT_FLOAT_EQ( expr0_, expr1_ )
//------------------------------------------------------------------------
// Checks to see if the two expressions are within eps_ of each other.

#define UTST_ASSERT_FLOAT_EQ( expr0_, expr1_, eps_ ) \
  if ( fabs( (expr0_) - (expr1_) ) > (double) (eps_) ) {                  \
  printf(" - [ " COLOR_RED "FAILED" COLOR_RESET " ] Line %d:  %f != %f\n", __LINE__, (expr0_), (expr1_)); \
    exit( 1 ); \
  } else { \
    printf(" - [ " COLOR_GREEN "passed" COLOR_RESET " ] Line %d:  %f == %f\n", __LINE__, (expr0_), (expr1_)); \
  }

#endif
