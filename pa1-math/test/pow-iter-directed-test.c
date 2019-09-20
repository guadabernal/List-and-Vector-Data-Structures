//========================================================================
// pow-iter-directed-test.c
//========================================================================
// This section contains directed tests that target different categories
// (e.g., small inputs, large inputs, negative inputs, etc.) for the
// pow-iter function.
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
#include <stdlib.h>
#include <math.h>
#include "utst.h"
#include "pow-iter.h"

//------------------------------------------------------------------------
// test_case_1_small_large
//------------------------------------------------------------------------
// Directed tests for small base with large exponent
void test_case_1_small_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter(   1, 100 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1.1, 300 ) / 2617010996188.4634, 1.0, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_2_small_zero
//------------------------------------------------------------------------
// Directed tests for small base with zero exponent
void test_case_2_small_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 3, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1.2, 0 ), 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_3_small_small
//------------------------------------------------------------------------
// Directed tests for small base with small exponent
void test_case_3_small_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1, 1 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1, 2 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1.3, 3 ), 2.1970, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_4_zero_large
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_4_zero_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 125 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 3895 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_5_zero_zero
//------------------------------------------------------------------------
// Directed tests for zero base with zero exponent
void test_case_5_zero_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 0 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_6_zero_small
//------------------------------------------------------------------------
// Directed tests for zero base with small exponent
void test_case_6_zero_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 1 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 2 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0, 3 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_7_large_large
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_7_large_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 12, 10 ) / 61917364224 , 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 9, 12 ) / 282429536481, 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 11, 9 ) / 2357947691, 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_8_large_zero
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_8_large_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 2501, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 354, 0 ), 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_9_large_small
//------------------------------------------------------------------------
// Directed tests for large base with small exponent
void test_case_9_large_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 300, 1 ), 300.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 251, 2 ), 63001.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 54, 3 ), 157464.0000, 0.0001 );
}

int main( int argc, char* argv[] )
{

  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_small_large();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_small_zero();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_small_small();
  if ( ( n == 0 ) || ( n == 4 ) ) test_case_4_zero_large();
  if ( ( n == 0 ) || ( n == 5 ) ) test_case_5_zero_zero();
  if ( ( n == 0 ) || ( n == 6 ) ) test_case_6_zero_small();
  if ( ( n == 0 ) || ( n == 7 ) ) test_case_7_large_large();
  if ( ( n == 0 ) || ( n == 8 ) ) test_case_8_large_zero();
  if ( ( n == 0 ) || ( n == 9 ) ) test_case_9_large_small();
    
  printf( "\n" );
  return 0;
}
