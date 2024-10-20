#ifndef VECTOR_H
#define VECTOR_H

typedef enum {
    TYPE_INT, 
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR
} VectorType;

typedef struct {
    void* array;
    int size;
    int capacity;
    VectorType type;
} Vector;

Vector vector(VectorType type, int size);
void vector_insert(Vector* array, void* item, int index);

#endif
