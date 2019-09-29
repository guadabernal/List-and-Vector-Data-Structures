//========================================================================
// list-find-eval.c
//========================================================================
// This program evalutes the performance of the function by running for
// multiple trials and averaging the elapsed run times.

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// Input dataset
//------------------------------------------------------------------------

#include "list.dat"

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  int lst_size;
  if ( argc ==2 ) {
    lst_size = atoi( argv[1] );

    if ( lst_size <= 0 || lst_size > size_data ){
      printf( "Number of finds must be within (0, %d]!\n", size_data );
      return 1;
    }

  } else {
    printf(
      "Please specify the size of the list from the command line like"
      " the following:\n"
      "./list-find-eval n\n"
      "Where n is the size of the list\n"
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

  printf( "Evaluating %d finds on %d-element list for %d times\n",
          nfinds, lst_size, nsubtrials );

  // Prepare data

  // Reset memory counter
  ece2400_mem_reset();

  list_int_t lst;
  list_int_construct( &lst );

  // Push back data to list
  for ( int i = 0; i < lst_size; i++ )
    list_int_push_back( &lst, data[i] );

  // Get heap usage
  heap_usage_total = ece2400_mem_get_usage();

  // Generate a sequence of values to find. 50% of them are in the list
  // and 50% are not
  srand( 0xfeedC0DE);

  int* value_to_find = malloc( sizeof(int) * nfinds );
  int* find_ref      = malloc( sizeof(int) * nfinds );
  int* find_result   = malloc( sizeof(int) * nfinds );

  for ( int i = 0; i < nfinds; i++ ){
    // 50% of the time add a number that is in the list
    if ( rand() % 2 ){
      value_to_find[i] = data[ rand() % lst_size ];
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
        find_result[k] = list_int_find( &lst, value_to_find[k] );

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
      list_int_destruct( &lst );
      free( value_to_find );
      free( find_ref );
      free( find_result );
      return 1;
    }
  }

  printf( "Verification passed\n" );

  // Free the heap

  list_int_destruct( &lst );
  free( value_to_find );
  free( find_ref );
  free( find_result );

  return 0;
}
