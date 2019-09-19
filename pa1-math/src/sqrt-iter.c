//========================================================================
// sqrt-iter.c
//========================================================================
// Baseline implementation of the sqrt function

#include "sqrt-iter.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX

int sqrt_iter( int x )
{
  if( x == 0 ) return 0;
  if( x == 1 ) return 1;
  if (x < 0 ) return -1;

  else {
    for( int i = 0; i < x; i++ ) {
  	  if( i * i >= x ) return i - 1;
    }
  }
  return x;
}

