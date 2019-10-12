//========================================================================
// list.h
//========================================================================
// Interface for doubly linked list

#ifndef LIST_H
#define LIST_H

typedef struct _node_t {
  size_t          value;
  struct _node_t* next_ptr;
  struct _node_t* prev_ptr;
}
node_t;

typedef struct {
  size_t  size;
  node_t* head_ptr;
  node_t* tail_ptr;
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
