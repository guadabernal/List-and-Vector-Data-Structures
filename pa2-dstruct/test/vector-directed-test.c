//========================================================================
// vector-directed-test.c
//========================================================================
// This file contains directed tests for vector-related functions.

#include <stdio.h>
#include "utst.h"
#include "vector.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests one element push back.

void test_case_1_simple_push_back()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  vector_int_push_back_v1( &vec, 0xbad22222 );
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), 1          );
  UTST_ASSERT_INT_EQ( vector_int_at  ( &vec, 0 ), 0xbad22222 );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_2_simple_find
//------------------------------------------------------------------------
// Push 2 elements and see if they can still be found.

void test_case_2_simple_find()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // Push back some elements
  for ( int i = 0; i < 2; i++ )
    vector_int_push_back_v1( &vec, i );

  // Try finding them
  for ( int i = 0; i < 2; i++ )
    UTST_ASSERT_TRUE( vector_int_find( &vec, i ) )

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 2 );

  vector_int_destruct( &vec );
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Add other test cases here
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple_push_back();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_simple_find();

  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Add your test cases here
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

}
