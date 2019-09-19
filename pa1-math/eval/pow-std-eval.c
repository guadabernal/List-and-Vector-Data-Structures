//========================================================================
// pow-std-eval.c
//========================================================================
// This program evalutes the performance of the function implemented in the
// standard C math library by running for multiple trials and averaging the
// elapsed run times.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  // Get base and exponent from the command line.
  double base;
  int exponent;
  if ( argc == 3 ){
    base     = atof( argv[1] );
    exponent = atoi( argv[2] );
  }
  else {
    printf("Please specify base and exponent from the command line like the following:\n"
           "./pow-std-eval b e\n"
           "Where b is base and e is exponent.\n");
    return 1;
  }
  printf("Evaluating base: %f, exponent %d\n", base, exponent );

  // Run many trials so we can average the run times. Within each trial,
  // run enough subtrials so that the total runtime of the trial is at
  // least a few seconds. This avoids precision issues with
  // gettimeofday().

  int ntrials    = 5;
  int nsubtrials = 1e7;

  // Run the experiment and track time using gettimeofday()

  double result;

  double elapsed_avg = 0.0;

  for ( int i = 0; i < ntrials; i++ ) {

    // Track time using timers

    struct timeval start;
    struct timeval end;

    // Start tracking time

    gettimeofday( &start, NULL );

    // Run for at least a few hundred microseconds to avoid precision issues

    for ( int j = 0; j < nsubtrials; j++ )
      result = pow( base, exponent );

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

  double ref = pow( base, exponent );
  float accuracy = result / ref;
  if ( accuracy < 0.9999 || accuracy > 1.0001 ){
    printf( "Error: verification failed, base %f to the exponent %d has result %f (but ref is %f)\n",
      base, exponent, result, ref );
    return 1;
  }
  printf("Verification passed\n");

  return 0;
}
