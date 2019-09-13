//========================================================================
// sqrt-recur-basic-test.c
//========================================================================
// This file contains the tests for the sqrt_recur function

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-recur.h"

int main() {

  //------------------------------------------------------------------------
  // Basic Test
  //------------------------------------------------------------------------
  // This is a simple test case to check that the most basic functionality
  // works correctly.

  // Basic test: Check that sqrt(5) = 2

  // Do not add any additional tests here
  UTST_ASSERT_INT_EQ( sqrt_recur( 5 ), 2 );

  return 0;

  //<'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}
