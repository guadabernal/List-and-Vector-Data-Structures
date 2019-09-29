//========================================================================
// vector-find-eval.c
//========================================================================
// This program evalutes the performance of the function by running for
// multiple trials and averaging the elapsed run times.

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// Input dataset
//------------------------------------------------------------------------

#include "vector.dat"

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  int vec_size;
  if ( argc ==2 ) {
    vec_size = atoi( argv[1] );

    if ( vec_size <= 0 || vec_size > size_data ){
      printf( "Number of finds must be within (0, %d]!\n", size_data );
      return 1;
    }

  } else {
    printf(
      "Please specify the size of the vector from the command line like"
      " the following:\n"
      "./vector-find-eval n\n"
      "Where n is the size of the vector\n"
    );
    return 1;
  }

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  const int ntrials    = 5;
  const int nsubtrials = 100;
  const int nfinds     = 5000;

  double elapsed;
  double elapsed_total = 0.0;

  size_t heap_usage_total;

  printf( "Evaluating %d finds on %d-element vector for %d times\n",
          nfinds, vec_size, nsubtrials );

  // Prepare data

  // Reset memory counter
  ece2400_mem_reset();

  vector_int_t vec;
  vector_int_construct( &vec );

  // Push back data to vector
  for ( int i = 0; i < vec_size; i++ )
    vector_int_push_back_v2( &vec, data[i] );

  // Get heap usage
  heap_usage_total = ece2400_mem_get_usage();

  // Generate a sequence of values to find. 50% of them are in the vector
  // and 50% are not
  srand( 0xfeedC0DE);

  int* value_to_find = malloc( sizeof(int) * nfinds );
  int* find_ref      = malloc( sizeof(int) * nfinds );
  int* find_result   = malloc( sizeof(int) * nfinds );

  for ( int i = 0; i < nfinds; i++ ){
    // 50% of the time add a number that is in the vector
    if ( rand() % 2 ){
      value_to_find[i] = data[ rand() % vec_size ];
      find_ref[i]      = 1;
    }
    else{
      value_to_find[i] = max_value + 1; // A number that cannot be found
      find_ref[i]      = 0;
    }
  }

  // Timing loop

  for ( int i = 0; i < ntrials; i++ ) {

    // Start tracking time for push back
    ece2400_timer_reset();

    for ( int j = 0; j < nsubtrials; j++ ){

      // Push back new data elements
      for ( int k = 0; k < nfinds; k++ )
        find_result[k] = vector_int_find( &vec, value_to_find[k] );

    }

    // Stop tracking time for push back
    elapsed = ece2400_timer_get_elapsed();

    // Accumulate result
    elapsed_total += elapsed;

    printf( "Elapsed time for trial %d is %fs\n", i, elapsed );

  }

  // Calculate average elapsed time per trial
  double elapsed_avg = elapsed_total / ntrials;

  printf( "Average elapsed time is %fs, heap usage is %zu byte\n",
          elapsed_avg, heap_usage_total );

  // Verify find results

  for ( int i = 0; i < nfinds; i++ ){
    if ( find_result[i] != find_ref[i] ){
      printf( "Verication failed for the %d-th find! Should be %d but was %d\n",
              i, find_ref[i], find_result[i] );
      vector_int_destruct( &vec );
      free( value_to_find );
      free( find_ref );
      free( find_result );
      return 1;
    }
  }

  printf( "Verification passed\n" );

  // Free the heap

  vector_int_destruct( &vec );
  free( value_to_find );
  free( find_ref );
  free( find_result );

  return 0;
}
