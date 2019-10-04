//========================================================================
// list-directed-test.c
//========================================================================
// This section contains directed tests for list-related functions.

#include <stdio.h>
#include "utst.h"
#include "list.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests one element push back.

void test_case_1_simple_push_back()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );

  list_int_push_back( &lst, 0x22222bad );
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), 1          );
  UTST_ASSERT_INT_EQ( list_int_at  ( &lst, 0 ), 0x22222bad );

  list_int_destruct( &lst );
}

//------------------------------------------------------------------------
// test_case_2_simple_find
//------------------------------------------------------------------------
// Push 2 elements and see if they can still be found.

void test_case_2_simple_find()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );

  // Push back some elements
  for ( int i = 0; i < 2; i++ )
    list_int_push_back( &lst, i );

  // Try finding them
  for ( int i = 0; i < 2; i++ )
    UTST_ASSERT_TRUE( list_int_find( &lst, i ) )

  // Check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 2 );

  list_int_destruct( &lst );
}

//------------------------------------------------------------------------
// test_case_3_large_find
//------------------------------------------------------------------------
// Push 1000 elements and see if they can still be found.

void test_case_3_large_find()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );

  // Push back some elements
  for ( int i = 0; i < 1000; i++ )
    list_int_push_back( &lst, i );

  // Try finding them
  for ( int i = 0; i < 1000; i++ )
    UTST_ASSERT_TRUE( list_int_find( &lst, i ) )

  // Check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 1000 );

  list_int_destruct( &lst );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple_push_back();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_simple_find();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_large_find();

  return 0;
}
