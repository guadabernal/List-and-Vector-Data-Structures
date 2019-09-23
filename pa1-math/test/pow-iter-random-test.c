//========================================================================
// pow-iter-random-test.c
//========================================================================
// This file contains tests with randomly generated inputs for the
// pow_iter function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utst.h"
#include "pow-iter.h"

void test_case_1( int numIter, double base_min, double base_max, int exp_min, int exp_max )
{
  double base;
  int exponent;
  for ( int i = 0; i < numIter; ++i ) {
    base = ( rand() / ( (double)RAND_MAX ) * ( base_max - base_min ) ) + base_min;
    exponent = ( rand() / ( (double)RAND_MAX ) * ( exp_min - exp_max ) ) + exp_min;
    UTST_ASSERT_FLOAT_EQ( pow_iter( base, exponent ), pow( base, exponent ), 0.0001 );  
  }	
}


int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );
  if ( n == 0 || n == 1 ) test_case_1(20, 0, 13, 1, 9);
  //UTST_ASSERT_FALSE( n + 1 );

  return 0;
}
