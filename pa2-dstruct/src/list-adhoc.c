//========================================================================
// list-main.c
//========================================================================
// This file contains an ad-hoc test for list-related functions

#include <stdio.h>
#include "list.h"

int main() {

  list_int_t lst;
  list_int_construct ( &lst );
  list_int_push_back ( &lst, 11 );
  list_int_push_back ( &lst, 12 );
  list_int_push_back ( &lst, 13 );

  printf( "Value stored at index 0 is %d\n", list_int_at( &lst, 0 ) );
  printf( "Value stored at index 1 is %d\n", list_int_at( &lst, 1 ) );
  printf( "Value stored at index 2 is %d\n", list_int_at( &lst, 2 ) );

  list_int_destruct  ( &lst );

  return 0;
}
