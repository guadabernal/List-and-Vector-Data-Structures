//========================================================================
// pow-recur-basic-test.c
//========================================================================
// This file contains the tests for the pow_recur function

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "pow-recur.h"

int main() {

  //------------------------------------------------------------------------
  // Basic Test
  //------------------------------------------------------------------------
  // This is a simple test case to check that the most basic functionality
  // works correctly.

  // Basic test: Check that 2.0 ^ 4 = 16.0
  // Epsilon value is 0.001 (i.e., 99.99% similarity)

  // Do not add any additional tests here
  UTST_ASSERT_FLOAT_EQ( pow_recur( 2.0, 4 ), 16.0, 0.001 );

  //<'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
