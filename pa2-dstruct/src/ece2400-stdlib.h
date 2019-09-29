//========================================================================
// ece2400-stdlib.h
//========================================================================
// Standard library for ece2400.
//
// DO NOT CHANGE THE FOLLOWING CODE!
//
// Author : Yanghui Ou
//   Date : Sep 6, 2019

#ifndef ECE2400_STDLIB
#define ECE2400_STDLIB

//------------------------------------------------------------------------
// ece2400_malloc
//------------------------------------------------------------------------
// Allocate memory of size mem_size Return a pointer to the newly
// allocated memory or NULL if the allocation fails.

void* ece2400_malloc( size_t mem_size );

//------------------------------------------------------------------------
// ece2400_free
//------------------------------------------------------------------------
// Free the memory block associated with the pointer.
//
// NOTE:
//
// the memory block must be allocated using ece2400_malloc, otherwise it
// is going to cause error.

void ece2400_free( void* ptr );

//------------------------------------------------------------------------
// ece2400_mem_reset
//------------------------------------------------------------------------
// Resets the memory counter to 0.

void ece2400_mem_reset();

//------------------------------------------------------------------------
// ece2400_mem_get_usage
//------------------------------------------------------------------------
// Return the amount of heap space that has been allocated so far in a
// program.

size_t ece2400_mem_get_usage();

//------------------------------------------------------------------------
// ece2400_timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void ece2400_timer_reset();

//------------------------------------------------------------------------
// ece2400_timer_get_elapsed
//------------------------------------------------------------------------
//  Return the elapased time in seconds.

double ece2400_timer_get_elapsed();

#endif // ECE2400_STDLIB
