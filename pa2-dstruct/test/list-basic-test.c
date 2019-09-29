//========================================================================
// list-basic-test.c
//========================================================================
// This file contains simple test cases to check that the most basic
// functionality works correctly.
//
// Note:
//
// You are not required to add any additional tests here.

#include <stdio.h>
#include "utst.h"
#include "list.h"

int main() {

  printf( "Test list_int_construct and list_int_destruct\n" );

  {
    list_int_t lst;
    list_int_construct ( &lst );
    list_int_destruct  ( &lst );
  }

  // Basic push_back and get

  printf( "\nTest list_int_push_back and list_get\n" );

  {
    list_int_t lst;
    list_int_construct ( &lst );

    // Push data into the data structure

    list_int_push_back( &lst, 1 );

    // Access and test data

    UTST_ASSERT_INT_EQ( list_int_at( &lst, 0 ), 1 );

    // Test size

    UTST_ASSERT_INT_EQ( list_int_size( &lst ), 1 );

    list_int_destruct( &lst );
  }

  // Basic find

  printf( "\nTest list_int_find\n" );

  {
    list_int_t lst;
    list_int_construct ( &lst );

    // Push data into the data structure

    list_int_push_back( &lst, 1 );
    list_int_push_back( &lst, 2 );
    list_int_push_back( &lst, 3 );

    // Test find

    UTST_ASSERT_INT_EQ( list_int_find( &lst, 3 ), 1 );

    list_int_destruct( &lst );
  }

  return 0;
}
