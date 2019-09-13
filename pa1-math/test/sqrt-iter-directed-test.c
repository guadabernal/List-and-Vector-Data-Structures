//========================================================================
// sqrt-iter-directed-test.c
//========================================================================
// This file contains the directed tests that target different categories
// for the sqrt_iter function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-iter.h"
#include <limits.h> // for INT_MAX

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Test case with simple inputs.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_iter( 0 ), 0 );
  UTST_ASSERT_INT_EQ( sqrt_iter( 1 ), 1 );
}

//------------------------------------------------------------------------
// test_case_2_negative
//------------------------------------------------------------------------
// Test case with negative inputs.

void test_case_2_negative()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_iter( -10 ), -1 );
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement test cases for directed testing here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_simple();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_negative();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
