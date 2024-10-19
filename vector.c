#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void* vector(VectorType type, int size) {
    /*
     * This function creates a vector with the size that you pass. it needs two arg:
     * - The type that the vector will use;
     * - The size that the vector will have.
     * 
     * Returns a pointer to the vector or NULL if allocation fails.
     */
    if (size <= 0) {
        printf("Size must be greater than zero.\n");
        return NULL;
    }

    void* pointer_to_array = NULL;

    switch (type) {
        case TYPE_INT:
            pointer_to_array = malloc(size * sizeof(int));
            break;
        case TYPE_FLOAT:
            pointer_to_array = malloc(size * sizeof(float));
            break;
        case TYPE_DOUBLE:
            pointer_to_array = malloc(size * sizeof(double));
            break;
        case TYPE_CHAR:
            pointer_to_array = malloc(size * sizeof(char));
            break;
        default:
            printf("Invalid type.\n");
            return NULL;
    }
    if (pointer_to_array == NULL) {
        printf("Failed to allocate memory\n");
        return NULL;
    }
    return pointer_to_array;
}
