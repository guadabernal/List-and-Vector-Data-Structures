//========================================================================
// vector.h
//========================================================================
// Interfaces for resizable vector

#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  size_t size;
  size_t maxsize;
  int*   array;
}
vector_int_t;

void   vector_int_construct    ( vector_int_t* this );
void   vector_int_destruct     ( vector_int_t* this );
size_t vector_int_size         ( vector_int_t* this );
void   vector_int_push_back_v1 ( vector_int_t* this, int value );
void   vector_int_push_back_v2 ( vector_int_t* this, int value );
int    vector_int_at           ( vector_int_t* this, size_t idx );
int    vector_int_find         ( vector_int_t* this, int value );
void   vector_int_print        ( vector_int_t* this );

#endif // VECTOR_H
