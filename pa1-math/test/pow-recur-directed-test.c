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
  UTST_ASSERT_FLOAT_EQ( pow_recur(   1, 100 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1.1, 300 ) / 2617010996188.4634, 1.0, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_2_small_zero
//------------------------------------------------------------------------
// Directed tests for small base with zero exponent
void test_case_2_small_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 3, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1.2, 0 ), 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_3_small_small
//------------------------------------------------------------------------
// Directed tests for small base with small exponent
void test_case_3_small_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1, 1 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1, 2 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1.3, 3 ), 2.1970, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_4_zero_large
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_4_zero_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 125 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 3895 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_5_zero_zero
//------------------------------------------------------------------------
// Directed tests for zero base with zero exponent
void test_case_5_zero_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 0 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_6_zero_small
//------------------------------------------------------------------------
// Directed tests for zero base with small exponent
void test_case_6_zero_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 1 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 2 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, 3 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_7_large_large
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_7_large_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 12, 10 ) / 61917364224 , 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 9, 12 ) / 282429536481, 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 11, 9 ) / 2357947691, 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_8_large_zero
//------------------------------------------------------------------------
// Directed tests for zero base with large exponent
void test_case_8_large_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 2501, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 354, 0 ), 1.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_9_large_small
//------------------------------------------------------------------------
// Directed tests for large base with small exponent
void test_case_9_large_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 300, 1 ), 300.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 251, 2 ), 63001.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 54, 3 ), 157464.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_10_negative_all
//------------------------------------------------------------------------
// Directed tests for negative base with any exponent
void test_case_10_negative_all()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -1, 1 ), -1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -3, 0 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -10, 2 ), 100.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -8, 12 ) / 68719476736.0000, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -1.2, 3 ), -1.7280000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -3, 13 ) / 1594323.0000, -1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -3, 3 ), -27.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_11_all_negative
//------------------------------------------------------------------------
// Directed tests for all bases with negative exponent
void test_case_11_all_negative()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 1, -3 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 3, -10 ) / 0.00001693508, 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 13, -2 ) / 0.00591715976, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( 2, -3 ), 0.125, 0.0001 );
  // this case is infinity  and should therefore return the following
  UTST_ASSERT_FLOAT_EQ( pow_recur( 0, -1 ), INFINITY, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_12_negative_negative
//------------------------------------------------------------------------
// Directed tests for all negative bases with negative exponents
void test_case_12_negative_negative()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -1, -1 ), -1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -3, -10 ) / 0.00001693508, 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -13, -2 ) / 0.00591715976, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -2, -9 ) / 0.001953125, -1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -10, -3 ) / 0.0010, -1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_recur( -2, -3 ), -0.125, 0.0001 );
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  // check zero base
  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_small_large();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_small_zero();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_small_small();
  // Check zero base
  if ( ( n == 0 ) || ( n == 4 ) ) test_case_4_zero_large();
  if ( ( n == 0 ) || ( n == 5 ) ) test_case_5_zero_zero();
  if ( ( n == 0 ) || ( n == 6 ) ) test_case_6_zero_small();
  // Check large base
  if ( ( n == 0 ) || ( n == 7 ) ) test_case_7_large_large();
  if ( ( n == 0 ) || ( n == 8 ) ) test_case_8_large_zero();
  if ( ( n == 0 ) || ( n == 9 ) ) test_case_9_large_small();
  // Check combinations with negative numbers
  if ( ( n == 0 ) || ( n == 10 ) ) test_case_10_negative_all();
  if ( ( n == 0 ) || ( n == 11 ) ) test_case_11_all_negative();
  if ( ( n == 0 ) || ( n == 12 ) ) test_case_12_negative_negative();

  printf( "\n" );
  return 0;
}
