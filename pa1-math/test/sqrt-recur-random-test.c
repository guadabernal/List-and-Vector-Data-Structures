//========================================================================
// sqrt-recur-test.c
//========================================================================
// This file contains the tests for the sqrt_recur function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-recur.h"
#include <limits.h> // for INT_MAX

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement your random test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

int main( int argc, char * argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  printf( "%d", n);
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test case here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  //------------------------------------------------------------------------
  // Students: Please comment out the following UTST_ASSERT_FALSE macro as
  // you add your random test cases. Otherwise, you tests will never pass!!!
  //------------------------------------------------------------------------
  //UTST_ASSERT_FALSE( n + 1 );

  return 0;
}
