//========================================================================
// vector-random-test.c
//========================================================================
// This file contains contains random tests for vector-related functions.

#include <stdio.h>
#include "utst.h"
#include "vector.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Students: This test case does nothing. You need to replace this test
// case with your own random test case.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  srand( 0xDeadFa11 );

  // Defines a list, constructs  it, define variables and array size
  vector_int_t vec;
  vector_int_construct( &vec );
  const int vec_size  = rand()%100;
  int *values_in_vec = (int *)malloc(vec_size * sizeof(int));

  // Fill list with random numbers and add to the  array
  for( int  i = 0; i < vec_size; i++) {
    int num = rand()%100;
    vector_int_push_back_v1( &vec, num );
    values_in_vec[i] = num;
  }

  // Assert that all the nodes within the list have the correct values assigned
  for( int  i = 0; i < vec_size; i++) {
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, i ), values_in_vec[i] );
  }

  // Check list size is correct
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), vec_size  );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_2_check_rand
//------------------------------------------------------------------------
// Pushes a large amount of random number of nodes into the vector, checks
// that the size of the list is correct and finds a random number of random
// nodes in the list and checks the values are correct.

void test_case_2_check_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a vector, constructs  it, define variables and array size
  vector_int_t vec;
  vector_int_construct( &vec );
  const int vec_size  = 1000;
  int *values_in_vec = (int *)malloc(vec_size * sizeof(int));
  int num_values_check = rand()%100;

  // Fill list with 1000 random numbers and add to the  array
  for( int  i = 0; i < vec_size; i++) {
    int num = rand()%100;
    vector_int_push_back_v1( &vec, num );
    values_in_vec[i] = num;
  }

  // Assert that  a random number of random nodes within the list
  // have the correct values assigned
  for( int  i = 0; i < num_values_check; i++) {
    int node_to_check = (rand() % (vec_size + 1)) + vec_size;
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, node_to_check), values_in_vec[node_to_check]);
  }

  // Check list size is correct
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), vec_size  );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_3_find_rand
//------------------------------------------------------------------------
// Pushes a random number of nodes into the vector, checks that the size of
// the vector is correct and tries to find a random number of random nodes in
// the vector and not in the list as well.

void test_case_3_find_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a list, constructs  it, define variables and array size
  vector_int_t vec;
  vector_int_construct( &vec );
  const int vec_size  = rand()%100;
  int *values_in_vec = (int *)malloc(vec_size * sizeof(int));

  // Fill list with random numbers and add to the  array
  for( int  i = 0; i < vec_size; i++) {
    int num = rand()%100;
    vector_int_push_back_v1( &vec, num );
    values_in_vec[i] = num;
  }

  // Assert that  a random number of random nodes within the list have thecorrect values assigned
  for( int  i = 0; i < vec_size; i++) {
    int node_to_check = (rand() % (vec_size + 1)) + vec_size;
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, values_in_vec[node_to_check]), 1);
  }

  //  <<<<<<<<<<<<<<<<<<<< check when values_in_list returns 0 (value not in list) ????  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  // Check list size is correct
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), vec_size  );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_4_check_v2_rand
//------------------------------------------------------------------------
// Pushes a large amount of random number of nodes into the end of the vector,
// checks that the size of the list is correct and finds a random number of
// random nodes in the list and checks the values are correct.

void test_case_4_check_v2_rand()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // Defines a vector, constructs  it, define variables and array size
  vector_int_t vec;
  vector_int_construct( &vec );
  const int vec_size  = 1000;
  int *values_in_vec = (int *)malloc(vec_size * sizeof(int));
  int num_values_check = rand()%100;

  // Fill list with 1000 random numbers and add to the array
  for( int  i = 0; i < vec_size; i++) {
    int num = rand()%100;
    vector_int_push_back_v2( &vec, num );
    values_in_vec[vec_size - i] = num;
  }

  // Assert that  a random number of random nodes within the list
  // have the correct values assigned
  for( int  i = 0; i < num_values_check; i++) {
    int node_to_check = (rand() % (vec_size + 1)) + vec_size;
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, node_to_check), values_in_vec[node_to_check]);
  }

  // Check list size is correct
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), vec_size  );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_1_simple();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_find_rand();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_4_check_v2_rand();

  return 0;
}
