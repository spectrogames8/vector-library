#ifndef VECTOR_H
#define VECTOR_H

typedef enum {
    TYPE_INT, 
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR
} VectorType;

void* vector(VectorType type, int size);

#endif
