//========================================================================
// list-random-test.c
//========================================================================
// This file contains the tests with randomly generated inputs

#include <stdio.h>
#include "utst.h"
#include "list.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// This test case does nothing. You need to replace this test
// case with your own random test case.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement a valid test case.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Please delete this assertion otherwise your test will always fail
  UTST_ASSERT_TRUE(0);
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Add other random test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  return 0;
}
