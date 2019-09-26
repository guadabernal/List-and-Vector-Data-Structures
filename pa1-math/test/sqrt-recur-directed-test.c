//========================================================================
// sqrt-recur-directed-test.c
//========================================================================
// This file contains the directed tests that target different categories
// for the sqrt_recur function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-recur.h"
#include <limits.h> // for INT_MAX

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Test case with simple inputs.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 0 ), 0 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 1 ), 1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 4 ), 2 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 25 ), 5 );
}

//------------------------------------------------------------------------
// test_case_2_negative
//------------------------------------------------------------------------
// Test case with negative inputs.

void test_case_2_negative()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( -10 ), -1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( -220 ), -1 );
}

//------------------------------------------------------------------------
// test_case_3_round_up
//------------------------------------------------------------------------
// Test case with inputs slightly smaller than a perfect square.

void test_case_3_round_smaller()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 35 ), 5 );
}

//------------------------------------------------------------------------
// test_case_4_round_down
//------------------------------------------------------------------------
// Test case with inputs slightly larger than a perfect square.

void test_case_4_round_larger()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 37 ), 6 );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_simple();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_negative();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_round_smaller();
  if ( ( n == 0 ) || ( n == 4 ) ) test_case_4_round_larger();

  return 0;
}
