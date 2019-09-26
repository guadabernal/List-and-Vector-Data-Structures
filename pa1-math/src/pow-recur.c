//========================================================================
// pow-recur.c
//========================================================================
// Alternative implementation of the pow function

#include "pow-recur.h"
#include <stdio.h>

double pow_recur( double base, int exponent )
{
  double total = 1;
  if( exponent > 0 ) {
    if( ( exponent % 2 ) == 0 )
      total = pow_recur( base * base, exponent / 2 );
    else
      total = base * pow_recur( base, exponent - 1 );
  }
  else if( exponent < 0 ) {
    total = 1.0 / pow_recur( base, -exponent );
  }
  return total;
}
