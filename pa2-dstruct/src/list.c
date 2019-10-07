//========================================================================
// list.c
//========================================================================
// Implementation of the list functions.
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
#include "list.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// list_int_construct
//------------------------------------------------------------------------
// Construct the list_int_t and initialize the fields inside.

void list_int_construct( list_int_t* this )
{
  this->head_ptr = NULL;
  this->tail_ptr = NULL;
  this->size = 0;
}

//------------------------------------------------------------------------
// list_int_destruct
//------------------------------------------------------------------------
// Destruct the list_int_t, freeing any dynamically allocated memory if
// necessary.

void list_int_destruct( list_int_t* this )
{
  while ( this->head_ptr != NULL ) {
    node_t* temp = this->head_ptr;
    if ( this->head_ptr == NULL ) {
      return;
    }
    if ( this->head_ptr->next_ptr != NULL ) {
      this->head_ptr->next_ptr->prev_ptr = NULL;
    }
    if ( this->tail_ptr == this->head_ptr ) {
      this->tail_ptr = NULL;
    }
    this->head_ptr = this->head_ptr->next_ptr;
    ece2400_free ( temp );
  }
}

//------------------------------------------------------------------------
// list_int_size
//------------------------------------------------------------------------
// Get the number of elements in the list.

size_t list_int_size( list_int_t* this )
{
  return this->size;
}

//------------------------------------------------------------------------
// list_int_push_back
//------------------------------------------------------------------------
// Push a new value into the list_int_t.

void list_int_push_back( list_int_t* this, int value )
{
  node_t* new_node = ( node_t* ) ece2400_malloc ( sizeof ( node_t ) );
  new_node->value = value;
  if ( this->tail_ptr != NULL ) this->tail_ptr->next_ptr = new_node;
  new_node->prev_ptr = this->tail_ptr;
  new_node->next_ptr = NULL;
  this->tail_ptr = new_node;
  if ( this->head_ptr == NULL ) this->head_ptr = new_node;
  this->size = this->size + 1;

  // debugging
  // printf("pushed value %d to back\n", value);
  // list_int_print( this );
}

//------------------------------------------------------------------------
// list_int_at
//------------------------------------------------------------------------
// Pointer chase and return the value at the given index
// If the index is out of bound, then return 0.

int list_int_at( list_int_t* this, size_t idx )
{
  // debugging
  // printf("pushed value %d to back\n", value);
  // printf("checking value at idx = %zu\n", idx);
  // list_int_print( this );

  if( (int)idx > this->size ) {
    printf("MESSAGE: index larger than size size = %d idx = %zu \n", this->size, idx);
    return 0;
  }

  int i = 0;
  node_t* temp = this->head_ptr;

  while( i != (int)idx ) {
    temp = temp->next_ptr;
    i++;
  }
  return temp->value;
}

//------------------------------------------------------------------------
// list_int_find
//------------------------------------------------------------------------
// Search the list for a value and return whether a value is found or not.
// Returning 1 means found, and 0 means not found.

int list_int_find( list_int_t* this, int value )
{
  node_t* temp = this->head_ptr;
  while ( temp != NULL ) {
    if ( temp->value == value ) {
      return 1;
    }
    temp = temp->next_ptr;
  }
  return 0;
}

//------------------------------------------------------------------------
// list_int_print
//------------------------------------------------------------------------
// Print out the content of list_int_t.

void list_int_print( list_int_t* this )
{
  node_t* temp = this->head_ptr;
  while ( temp != NULL ) {
    printf ( "%d  ", temp->value );
    temp = temp->next_ptr;
  }
  printf("\n");
}
