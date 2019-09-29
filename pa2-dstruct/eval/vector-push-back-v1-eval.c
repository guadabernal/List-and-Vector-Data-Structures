//========================================================================
// vector-push-back-v1-eval.c
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
  int npush_backs;
  if ( argc ==2 ) {
    npush_backs = atoi( argv[1] );

    if ( npush_backs <= 0 || npush_backs > size_data ){
      printf( "Number of push backs must be within (0, %d]!\n", size_data );
      return 1;
    }

  } else {
    printf(
      "Please specify the number of push backs from the command line like"
      " the following:\n"
      "./vector-push-back-v1-eval n\n"
      "Where n is the number of push backs\n"
    );
    return 1;
  }

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  const int ntrials    = 5;
  const int nsubtrials = 1e4;

  double elapsed;
  double elapsed_total = 0.0;

  // Memory profiling variables

  size_t heap_usage;
  size_t heap_usage_total = 0;

  printf( "Evaluating %d push backs for %d times\n", npush_backs, nsubtrials );

  // Timing loop

  for ( int i = 0; i < ntrials; i++ ) {

    vector_int_t vec;

    // Start tracking time for push back
    ece2400_timer_reset();

    for ( int j = 0; j < nsubtrials; j++ ){

      // Construct vector
      vector_int_construct( &vec );

      // Push back new data elements
      for ( int k = 0; k < npush_backs; k++ )
        vector_int_push_back_v1( &vec, data[k] );

      // Destruct vector
      vector_int_destruct( &vec );
    }

    // Stop tracking time for push back
    elapsed = ece2400_timer_get_elapsed();

    // Push back once again to get heap usage

    // Reset memory counter
    ece2400_mem_reset();

    // Construct vector
    vector_int_construct( &vec );

    // Push back new data elements
    for ( int k = 0; k < npush_backs; k++ )
      vector_int_push_back_v1( &vec, data[k] );

    // Get heap usage
    heap_usage = ece2400_mem_get_usage();

    // Destruct vector
    vector_int_destruct( &vec );

    // Accumulate result
    elapsed_total    += elapsed;
    heap_usage_total += heap_usage;

    printf( "Elapsed time for trial %d is %fs, heap usage is %zu byte\n",
            i, elapsed,  heap_usage );

  }

  // Calculate average elapsed time per trial

  double elapsed_avg    = elapsed_total    / ntrials;
  size_t heap_usage_avg = heap_usage_total / ntrials;

  printf( "Average elapsed time is %fs, average heap usage is %zu byte\n",
          elapsed_avg, heap_usage_avg );

  // Verify push back results

  vector_int_t vec;
  vector_int_construct( &vec );

  for ( int k = 0; k < npush_backs; k++ )
    vector_int_push_back_v1( &vec, data[k] );

  for ( int i = 0; i < npush_backs; i++ ){
    int result = vector_int_at( &vec, i );
    if ( result != data[i] ){
      printf("Verification failed! the %d-th element should be %d but was %d\n",
              i, data[i], result );
      return 1;
    }
  }

  vector_int_destruct( &vec );

  printf( "Verification passed\n" );

  return 0;
}
