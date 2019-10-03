//========================================================================
// sqrt-iter.c
//========================================================================
// Baseline implementation of the sqrt function

#include "sqrt-iter.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX

int sqrt_iter( int x )
{
  int sqrt = 0;
  // check initial conditions first
  if( x == 0 ) sqrt = 0;
  if( x == 1 ) sqrt = 1;
  if( x == 2 ) sqrt = 1;
  if( x < 0 ) sqrt = -1;

  // iterate through from i = 0 until the integer closest to the sqrt of x is found
  else {
    for( int i = 0; i < x; i++ ) {
      int long sqr = (int long)(i) * i;
      if( sqr == x )
        return i;
      else if( sqr > x )
        return i - 1;
    }
  }
  return sqrt;
}
