#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Vector Declaration Function
Vector vector(VectorType type, int size) {
    /*
     * This function creates a vector with the size that you pass. it needs two args:
     * - The type that the vector will use;
     * - The size that the vector will have (needs to be bigger than 0).
     * 
     * Returns a pointer to the vector or NULL if allocation fails.
     */

    Vector vec;
    
    // Checks if vec size < 0, and if it is, turn the vec pointer into NULL and return.
    if (size < 0) {
        printf("Size must be zero or more.\n");
        vec.array = NULL;
        return vec;
    }

    void* pointer_to_array = NULL;

    // Creates the vector using calloc depending on the type
    // with the size passed in the function.
    // If type is invalid, turn the vec pointer into NULL and return.
    switch (type) {
        case TYPE_INT:
            pointer_to_array = calloc(size, sizeof(int));
            break;
        case TYPE_FLOAT:
            pointer_to_array = calloc(size, sizeof(float));
            break;
        case TYPE_DOUBLE:
            pointer_to_array = calloc(size, sizeof(double));
            break;
        case TYPE_CHAR:
            pointer_to_array = calloc(size, sizeof(char));
            break;
        default:
            printf("Invalid type.\n");
            vec.array = NULL;
            return vec;
    }

    // Checks if calloc failed
    if (pointer_to_array == NULL) {
        printf("Failed to allocate memory\n");
        vec.array = NULL;
        return vec;
    }

    int capacity = 0;

    /* 
     * Calculates the capacity that the vector has by checking
     * if type_vector[i] is equal to a empty value (int: 0, float: 0.0f, double: 0.0, char: '\0').
     * If somehow type is invalid, turn the vec pointer into NULL and return.
     */ 

    switch (type) {
        
        case TYPE_INT:
            int* int_vector = (int*) pointer_to_array;
            for (int i = 0; i < size; i++) {
                if (int_vector[i] == 0) {
                    capacity += 1;
                }
            }
        break;

        case TYPE_FLOAT:
            float* float_vector = (float*) pointer_to_array;
            for (int i = 0; i < size; i++) {
                if (float_vector[i] == 0.0f) {
                    capacity += 1;
                }
            }
            break;
        
        case TYPE_DOUBLE:
            double* double_vector = (double*) pointer_to_array;
            for (int i = 0; i < size; i++) {
                if (double_vector[i] == 0.0) {
                    capacity += 1;
                }
            }
            break;

        case TYPE_CHAR:
            char* char_vector = (char*) pointer_to_array;
            for (int i = 0; i < size; i++) {
                if (char_vector[i] == '\0') {
                    char_vector[i] = ' ';
                    capacity += 1;
                }
            }
            break;
        
        default:
            printf("Unknown Error.\n");
            vec.array = NULL;
            return vec;
    }

    // Assign the acquired values into the vec struct and return it.
    vec.array = pointer_to_array;
    vec.capacity = capacity;
    vec.size = size;
    vec.type = type;

    return vec;
}

// Will probably remake it

void vector_insert(Vector* array, void* item, int index) {
    if (array->array == NULL) {
        printf("Array does not exist.");
        return;
    }
    if (index < 0) {
        printf("Index is negative, invalid.");
        return;
    }
    if (index > array->size) {
        printf("Index is bigger than size, invalid.");
        return;
    }
    if (item == NULL) {
        printf("Item does not exist.");
        return;
    }
    switch (array->type) {
        case TYPE_INT:
            ((int*)array->array)[index] = *(int*)item;
            break;
        case TYPE_FLOAT:
            ((float*)array->array)[index] = *(float*)item;
            break;
        case TYPE_DOUBLE:
            ((double*)array->array)[index] = *(double*)item;
            break;
        case TYPE_CHAR:
            ((char*)array->array)[index] = *(char*)item;
            break;
    }
}
