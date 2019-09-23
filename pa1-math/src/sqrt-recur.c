//========================================================================
// sqrt-recur.c
//========================================================================
// Alternative implementation of the sqrt function

#include "sqrt-recur.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX

int help_func( int min, int max, int x )
{
  int ret_val = 0;
  int temp = ( (max - min) / 2 + min ) * ( ( max - min ) / 2 + min);
  
  if ( temp == x )
    ret_val = ( max - min ) / 2 + min;
  else if ( (max - min ) == 1 )
    ret_val = min;
  else if ( temp  > x )
    ret_val = help_func( min, (max - min) / 2 + min  , x );
  else if ( temp < x )
    ret_val = help_func( (max - min) / 2 + min , max, x );
  return ret_val;
}

int sqrt_recur( int x ) 
{
  if ( x < 0 ) return -1;
  if ( x == 0 ) return 0;
  if ( x == 1 ) return 1;
  return help_func( 0, x, x );
}

