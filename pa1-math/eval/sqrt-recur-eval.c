//========================================================================
// sqrt-recur-eval.c
//========================================================================
// This program evalutes the performance of the function by running for
// multiple trials and averaging the elapsed run times.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include "sqrt-recur.h"

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  // Get base and exponent from the command line.
  int x;
  if ( argc == 2 ){
    x = atoi( argv[1] );
  }
  else {
    printf("Please specify base and exponent from the command line like the following:\n"
           "./sqrt-recur-eval x\n"
           "Where x is the input.\n");
    return 1;
  }
  printf("Evaluating sqrt of %d\n", x );

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  int ntrials    = 5;
  int nsubtrials = 1e6;

  // Run the experiment and track time using gettimeofday()

  int result;

  double elapsed_avg = 0.0;

  for ( int i = 0; i < ntrials; i++ ) {

    // Track time using timers

    struct timeval start;
    struct timeval end;

    // Start tracking time

    gettimeofday( &start, NULL );

    // Run for at least a few hundred microseconds to avoid precision issues

    for ( int j = 0; j < nsubtrials; j++ )
      result = sqrt_recur( x );

    // Stop tracking time

    gettimeofday( &end, NULL );

    // Calculate elapsed time

    double elapsed = ( end.tv_sec - start.tv_sec ) +
                   ( ( end.tv_usec - start.tv_usec ) / 1000000.0 );

    elapsed_avg += elapsed;

    printf( "Elapsed time for trial %d is %f\n", i, elapsed );
  }

  // Calculate average elapsed time per trial

  elapsed_avg = elapsed_avg / ntrials;

  printf( "Elapsed time (averaged) is %f\n", elapsed_avg );

  // Verify the results

  int ref = sqrt( x );
  if ( result != ref ){
    printf( "Error: verification failed, sqrt of %d has result %d (but ref is %d)\n",
      x, result, ref );
    return 1;
  }
  printf("Verification passed\n");


  return 0;
}

