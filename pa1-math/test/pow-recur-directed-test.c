//========================================================================
// pow-recur-directed-test.c
//========================================================================
// This section contains directed tests that target different categories
// (e.g., small inputs, large inputs, negative inputs, etc.) for the
// pow-recur function.
//
// NOTE:
//
// floating-point precision errors add up when the exponent is
// very large, and the final result may be slightly different than
// expected but still very accurate (>99.99%). For example, the solution
// code for pow-iter and pow-recur has the following results for 1.1^300:
//
// - 2617010996188.463867 (staff solution for pow-iter)
// - 2617010996188.452637 (staff solution for pow-recur)
//
// Notice how values are slightly different, but still >99.99% identical.
//
// To address this, we test how close we are to the reference value and
// then check that we are within 99.99% of it. Do this by dividing the
// result value (from your function) by the reference value and then
// comparing to 1.00. Then use an epsilon of 0.0001 to test for 99.99%
// similarity:
//
//     UTST_ASSERT_FLOAT_EQ( my_result / my_ref, 1.0, 0.0001 );
//
// One example directed test with a large exponent is provided for you.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "pow-recur.h"

//------------------------------------------------------------------------
// test_case_1_small_large
//------------------------------------------------------------------------
// Directed tests for small base with large exponent

void test_case_1_small_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur(   1, 100 ),                      1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1.1, 300 ) / 2617010996188.4634, 1.0,    0.0001 );
}

//------------------------------------------------------------------------
// test_case_2_zero_small
//------------------------------------------------------------------------
// Directed tests for 0 base with small exponent

void test_case_2_zero_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 1 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 2 ), 0.0000, 0.0001 );
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Add more test cases for directed testing here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{

  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_small_large();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_zero_small();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
