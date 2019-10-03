//========================================================================
//vector-basic-test.c
//========================================================================
// This file contains simple test cases to check that the most basic
// functionality works correctly.
//
// Note:
//
// You are not required to add any additional tests here.

#include <stdio.h>
#include "utst.h"
#include "vector.h"

int main() {

  // Basic construct and destruct case

  printf( "Test vector_int_construct and vector_int_destruct\n" );

  {
    vector_int_t vec;
    vector_int_construct ( &vec ); // space for 1 element
    vector_int_destruct  ( &vec );
  }

  // Basic push_back and at

  printf( "\nTest vector_int_push_back_v1 and vector_int_at\n" );

  {
    vector_int_t vec;
    vector_int_construct( &vec ); // space for 1 element

    // Push data into the data structure
    vector_int_push_back_v1( &vec, 1 );

    // Access and test data
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, 0 ), 1 );

    // Test size
    UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 1 );

    vector_int_destruct( &vec );
  }

  // Basic find

  printf( "\nTest vector_int_find\n" );

  {
    vector_int_t vec;
    vector_int_construct( &vec ); // space for 1 element

    // Push data into the data structure

    vector_int_push_back_v1( &vec, 1 );
    vector_int_push_back_v1( &vec, 2 );
    vector_int_push_back_v1( &vec, 3 );

    // Test find
    UTST_ASSERT_INT_EQ( vector_int_find( &vec, 3 ), 1 );

    vector_int_destruct( &vec );
  }

}
