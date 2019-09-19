//========================================================================
// pow-iter.c
//========================================================================
// Baseline implementation of the pow function

#include "pow-iter.h"
#include <stdio.h>

double pow_iter( double base, int exponent )
{
  double total = 1;
  if ( exponent == 0 ) 
    return 1;
  if ( exponent == -1 )
	return -1;

  else if ( exponent > 0 ) {
  	while ( exponent > 0 ){
  		exponent -= 1;
  		total *= base;
  	}
  }
  else if (exponent < 0 ) {
  	while ( exponent < 0 ) {
  		exponent += 1;
  		total *= base;
  	}
  	 total = 1.0 / total;
  }

  return total;
}

