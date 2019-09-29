//========================================================================
// list.h
//========================================================================
// Interface for doubly linked list

#ifndef LIST_H
#define LIST_H

typedef struct {
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Define fields for list_int_t
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // We define a dummy field here to avoid warnings in the released code.
  // Please delete this field as you implement your data structure!
  int dummy;
}
list_int_t;

void   list_int_construct ( list_int_t* this );
void   list_int_destruct  ( list_int_t* this );
size_t list_int_size      ( list_int_t* this );
void   list_int_push_back ( list_int_t* this, int value );
int    list_int_at        ( list_int_t* this, size_t idx );
int    list_int_find      ( list_int_t* this, int value );
void   list_int_print     ( list_int_t* this );

#endif // LIST_H
