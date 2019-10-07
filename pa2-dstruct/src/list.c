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
  // Iterate through all the nodes
  // Make sure there are no pointer to dealocated memory before freeing the node
  while ( this->head_ptr != NULL ) {
    node_t* temp = this->head_ptr;

    // Set the pointer pointing to the current node being destructed to null
    // Head_ptr -> <- B -> <- C -> <- ...         Head_ptr -> B
    if ( this->head_ptr->next_ptr != NULL ) {
      this->head_ptr->next_ptr->prev_ptr = NULL;
    }

    // If the head is equal to the tail, set tail to NULL
    // Head -> <- Tail   Head -> Tail
    if ( this->tail_ptr == this->head_ptr ) {
      this->tail_ptr = NULL;
    }

    // Move to the next node and free the allocated memory
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
  // Creates a new node and assigns its 'value' field value
  node_t* new_node = ( node_t* ) ece2400_malloc ( sizeof ( node_t ) );
  new_node->value = value;


  // Assign values to the new node's pointer variables. If the tail_ptr is not null
  // then tail_ptr->next_ptr must be re-assigned before the tail_ptr is moved to the new_node
  if ( this->tail_ptr != NULL ) {
    this->tail_ptr->next_ptr  = new_node;
    new_node->prev_ptr        = this->tail_ptr;
  }
  else {
    new_node->prev_ptr = NULL;
  }
  new_node->next_ptr = NULL;

  // Modifies the 'this' tail pointer and if necessary, (in the case that this is
  // the first node) the head_ptr, to point at the new node as well
  this->tail_ptr = new_node;
  if ( this->head_ptr == NULL ) this->head_ptr = new_node;

  // Increment the size of the list
  this->size = this->size + 1;
}

//------------------------------------------------------------------------
// list_int_at
//------------------------------------------------------------------------
// Pointer chase and return the value at the given index
// If the index is out of bound, then return 0.

int list_int_at( list_int_t* this, size_t idx )
{
  // Checks if the index is larger than the size and returns 0
  if( (int)idx > this->size ) {
    return 0;
  }

  int i = 0;
  node_t* temp = this->head_ptr;

  // Iterates through idx nodes with the temp variable and returns the value at the idx index
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

  // if the value is found return 1, else traverse to the next node until
  // the null node is reached, then return 0
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
  // Use a temp variable to help itterate through the list
  node_t* temp = this->head_ptr;

  // Iterrate through the nodes printing their value until the node is null
  while ( temp != NULL ) {
    printf ( "%d  ", temp->value );
    temp = temp->next_ptr;
  }

  printf("\n");
}
