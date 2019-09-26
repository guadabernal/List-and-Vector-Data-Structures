//========================================================================
// sqrt-recur.c
//========================================================================
// Alternative implementation of the sqrt function

#include "sqrt-recur.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX

int help_func( int min, int max, int x )
{
  int m = (min + max) / 2;
  int sqr = m * m;
  int ret_val = m;
  if ( (max - min ) == 1 )
    ret_val = min;
  else if ( sqr  > x )
    ret_val = help_func( min, m, x );
  else if ( sqr < x )
    ret_val = help_func( m, max, x );
  return ret_val;
}

int sqrt_recur( int x )
{
  if ( x < 0 ) return -1;
  if ( x == 0 ) return 0;
  if ( x == 1 ) return 1;
  return help_func( 0, x, x );
}
