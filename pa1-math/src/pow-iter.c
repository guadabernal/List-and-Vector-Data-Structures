//========================================================================
// pow-iter.c
//========================================================================
// Baseline implementation of the pow function

#include "pow-iter.h"
#include <stdio.h>

double pow_iter( double base, int exponent )
{
  // total will be the value returned by the function pow
  double total = 1;

  // Check basic cases
  // The first case checks 0^(-1) which is equal to infinity...
  // ...the code is a work around for not having math.h
  if ( base == 0 ) {
    if ( exponent < 0 ) {
  	  double p;
  	  long unsigned int * a = (long unsigned int*)(&p);
  	  *a = 0x7FF0000000000000;
  	  return p;
    }
    else
      return 0;
  }
  if ( exponent == 0 ) 
    total =  1;

  // Checks all other cases 
  else if ( exponent > 0 ) {
  	while ( exponent > 0 ){
  	  exponent -= 1;
  	  total *= base;
  	}
  }
  else if ( exponent < 0 ) {
  	while ( exponent < 0 ) {
  	  exponent += 1;
  	  total *= base;
  	}
    total = 1.0 / total;
  }

  return total;
}

