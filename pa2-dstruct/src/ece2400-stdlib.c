//========================================================================
// ece2400-stdlib.c
//========================================================================
// Utility functions to support memory and performance profiling.
//
// Note:
//
// DO NOT CHANGE THE FOLLOWING CODE!
//
// Author: Yanghui Ou
//   Date: Sep 7, 2019

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------

size_t mem_usage = 0;

struct timeval start_time;
struct timeval end_time;

const double MILLION = 1000000.0;

//------------------------------------------------------------------------
// ece2400_malloc
//------------------------------------------------------------------------
// Allocate memory of size mem_size. Return a pointer to the newly
// allocated memory or NULL if the allocation fails.

void* ece2400_malloc( size_t mem_size )
{
  void* ptr = malloc( mem_size  + sizeof(size_t) );

  if ( ptr )
    mem_usage += mem_size;
  else
    return NULL;

  ( (size_t*)ptr )[0] = mem_size;

  return (void*)( ( (size_t*)ptr ) + 1 );
}

//------------------------------------------------------------------------
// ece2400_free
//------------------------------------------------------------------------
// Free the memory block that is allocated using ece2400_malloc. According
// to C standard, if ptr is NULL, no action occurs.

void ece2400_free( void* ptr )
{
  if ( ptr ){
    mem_usage -= ( (size_t*)ptr )[-1];
    free( ( ( (size_t*)ptr ) - 1 ) );
  }
}

//------------------------------------------------------------------------
// ece2400_mem_reset
//------------------------------------------------------------------------

void ece2400_mem_reset()
{
  mem_usage = 0;
}

//------------------------------------------------------------------------
// ece2400_mem_get_usage
//------------------------------------------------------------------------
// Return the amount of heap space that has been allocated so far in a
// program

size_t ece2400_mem_get_usage()
{
  return mem_usage;
}

//------------------------------------------------------------------------
// ece2400_timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void ece2400_timer_reset()
{
  gettimeofday( &start_time, NULL );
}

//------------------------------------------------------------------------
// ece2400_timer_get_elapsed
//------------------------------------------------------------------------
//  Return the elapased time in seconds.

double ece2400_timer_get_elapsed()
{
  gettimeofday( &end_time, NULL );
  double elapsed_time = ( end_time.tv_sec  - start_time.tv_sec ) +
                         ( end_time.tv_usec - start_time.tv_usec ) / MILLION;
  return elapsed_time;
}
