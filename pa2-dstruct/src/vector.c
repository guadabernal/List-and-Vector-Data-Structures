//========================================================================
// vector.c
//========================================================================
// Baseline implementation of the vector functions
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// vector_int_construct
//------------------------------------------------------------------------
// Construct the vector_int_t and initialize the fields inside

void vector_int_construct( vector_int_t* this )
{
  this->size = 0;
  this->maxsize = 0;

  // malloc here to size of 1?
  this->array = ( int* ) ece2400_malloc ( sizeof ( int ) );
}

//------------------------------------------------------------------------
// vector_int_destruct
//------------------------------------------------------------------------
// Destruct the vector_int_t, freeing any dynamically allocated memory if
// necessary

void vector_int_destruct( vector_int_t* this )
{
  // Free the allocated memory
  ece2400_free ( this->array );

  // Reset the vector elements
  this->array = NULL;
  this->size = 0;
  this->maxsize = 0;
}

//------------------------------------------------------------------------
// vector_int_size
//------------------------------------------------------------------------
// Get the number of elements in the vector.

size_t vector_int_size( vector_int_t* this )
{
  return this->size;
}

//------------------------------------------------------------------------
// vector_int_push_back_v1
//------------------------------------------------------------------------
// Push a new value into the vector_int_t, allocate just enough memory if
// the internal array is full.

void vector_int_push_back_v1( vector_int_t* this, int value )
{
  // If necessary allocate more mmemory
  if( this->size == this->maxsize ) {
     // Allocate one more spot
     this->maxsize = this->maxsize + 1;
  }

  // Insert 'value' into the array and increment the size
  (this->array)[this->size + 1] = value;
  this->size = this->size + 1;
}

//------------------------------------------------------------------------
// vector_int_push_back_v2
//------------------------------------------------------------------------
// Push a new value into the vector_int_t, doubles the size of the
// internal array if vector is full.

void vector_int_push_back_v2( vector_int_t* this, int value )
{
  if( this->size == this->maxsize ) {
     // Allocate twice the current maxsize
     this->maxsize = this->maxsize * 2;
  }

  // Insert 'value' into the array and increment the size
  (this->array)[this->size + 1] = value;
  this->size = this->size + 1;
}

//------------------------------------------------------------------------
// vector_int_at
//------------------------------------------------------------------------
// Access the internal array and return the value at the given index
// If the index is out of bound, then return 0

int vector_int_at( vector_int_t* this, size_t idx )
{
  if( idx > this->size ) {
    return 0;
  }
  return this->array[idx];
}

//------------------------------------------------------------------------
// vector_int_find
//------------------------------------------------------------------------
// Search the vector for a value and return whether a value is found or
// not. Returning 1 means found, and 0 means not found.

int vector_int_find( vector_int_t* this, int value )
{
  size_t i = 0;

  // Iterates through the array until i is size and returns 1 if 'value' is found
  while ( i < this->size ) {
    if ( this->array[i] == value ) {
      return 1;
    }
    i++;
  }
  return 0;
}

//------------------------------------------------------------------------
// vector_int_print
//------------------------------------------------------------------------
// Print out the content of vector_int_t

void vector_int_print( vector_int_t* this )
{
  for( int i = 0; i < (int)this->size; i++ ){
    printf("term i = %d  has value of %d\n", i, this->array[i]);
  }

}
