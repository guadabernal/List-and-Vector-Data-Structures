//========================================================================
// list-random-test.c
//========================================================================
// This file contains the tests with randomly generated inputs

#include <stdio.h>
#include "utst.h"
#include "list.h"

//------------------------------------------------------------------------
// test_case_1_write_rand
//------------------------------------------------------------------------
// Pushes a random number of nodes into the  list, checks that the size of
// the list is correct and that the int at each node is correct.

void test_case_1_write_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a list, constructs  it, define variables and array size
  list_int_t lst;
  list_int_construct( &lst );
  const int list_size  = rand()%100;
  int *values_in_list = (int *)malloc(list_size * sizeof(int));

  // Fill list with random numbers and add to the  array
  for( int  i = 0; i < list_size; i++) {
    int num = rand()%100;
    list_int_push_back( &lst, num );
    values_in_list[i]  =  num;
  }

  // Assert that all the nodes within the list have the correct values assigned
  for( int  i = 0; i < list_size; i++) {
    UTST_ASSERT_INT_EQ( list_int_at( &lst, i ), values_in_list[i] );
  }

  // Check list size is correct
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), list_size  );

  list_int_destruct( &lst );
  free(values_in_list);
}

//------------------------------------------------------------------------
// test_case_2_check_rand
//------------------------------------------------------------------------
// Pushes a large amount of random number of nodes into the list, checks that the size of
// the list is correct and finds a random number of random nodes in
// the list and checks the values are correct.

void test_case_2_check_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a list, constructs  it, define variables and array size
  list_int_t lst;
  list_int_construct( &lst );
  const int list_size  = 1000;
  int *values_in_list = (int *)malloc(list_size * sizeof(int));
  int num_values_check = rand()%100;

  // Fill list with 1000 random numbers and add to the  array
  for( int  i = 0; i < list_size; i++) {
    int num = rand()%100;
    list_int_push_back( &lst, num );
    values_in_list[i]  =  num;
  }

  // Assert that  a random number of random nodes within the list have the correct values assigned
  for( int  i = 0; i < num_values_check; i++) {
    int node_to_check = (rand() % (list_size + 1)) + list_size;
    UTST_ASSERT_INT_EQ( list_int_at( &lst, node_to_check), values_in_list[node_to_check]);
  }

  // Check list size is correct
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), list_size  );

  list_int_destruct( &lst );
  free(values_in_list);
}

//------------------------------------------------------------------------
// test_case_3_find_rand
//------------------------------------------------------------------------
// Pushes a random number of nodes into the list, checks that the size of
// the list is correct and tries to find a random number of random nodes in
// the list and not in the list as well.

void test_case_3_find_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a list, constructs  it, define variables and array size
  list_int_t lst;
  list_int_construct( &lst );
  const int list_size  = rand()%100;
  int *values_in_list = (int *)malloc(list_size * sizeof(int));
  int num_values_check = rand()%100;

  // Fill list with random numbers and add to the  array
  for( int  i = 0; i < list_size; i++) {
    int num = rand()%100;
    list_int_push_back( &lst, num );
    values_in_list[i]  =  num;
  }

  // Assert that  a random number of random nodes within the list have thecorrect values assigned
  for( int  i = 0; i < num_values_check; i++) {
    int node_to_check = (rand() % (list_size + 1)) + list_size;
    UTST_ASSERT_INT_EQ( list_int_find( &lst, values_in_list[node_to_check]), 1);
  }

  //  <<<<<<<<<<<<<<<<<<<< check when values_in_list returns 0 (value not in list) ????  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  // Check list size is correct
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), list_size  );

  list_int_destruct( &lst );
  free(values_in_list);
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_write_rand();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_check_rand();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_3_find_rand();

  return 0;
}
