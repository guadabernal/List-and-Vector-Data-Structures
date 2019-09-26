//========================================================================
// sqrt-recur-test.c
//========================================================================
// This file contains the tests for the sqrt_recur function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-recur.h"
#include <limits.h> // for INT_MAX

void test_case_1( int n, int x_min, int x_max ) {
  int x;
  for ( int i = 0; i < n; ++i) {
    x = ( rand() / ( (double)RAND_MAX ) * ( x_max - x_min ) ) + x_min;
    UTST_ASSERT_INT_EQ( sqrt_recur( x ), (int)sqrt( x ) );
  }
}

int main( int argc, char * argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n== 0 ) || (n == 1) ) test_case_1( 3, 0, 300 );

  //UTST_ASSERT_FALSE( n + 1 );

  return 0;
}
