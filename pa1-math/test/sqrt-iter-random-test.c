//========================================================================
// sqrt-iter-random-test.c
//========================================================================
// This file contains the tests with randomly generated inputs for the
// sqrt_iter function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-iter.h"
#include <limits.h> // for INT_MAX

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement your random test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test case here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  //------------------------------------------------------------------------
  // Students: Please comment out the following UTST_ASSERT_FALSE macro as
  // you add your random test cases. Otherwise, you tests will never pass!!!
  //------------------------------------------------------------------------
  UTST_ASSERT_FALSE( n + 1 );

  return 0;
}
