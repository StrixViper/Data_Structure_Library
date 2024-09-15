#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;     // Array of integers
    size_t size;   // Current number of elements
    size_t capacity; // Maximum capacity
} Vector;

// Initialize a vector with an initial capacity
Vector* createVector(size_t capacity) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = capacity;
    vector->data = (int *)malloc(capacity * sizeof(int));
    return vector;
}

// Add an element to the vector
void vectorPushBack(Vector *vector, int value) {
    if (vector->size >= vector->capacity) {
        // Double the capacity if needed
        vector->capacity *= 2;
        vector->data = (int *)realloc(vector->data, vector->capacity * sizeof(int));
    }
    vector->data[vector->size++] = value;
}

// Get the element at a specific index
int vectorGet(const Vector *vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    return vector->data[index];
}

// Free vector resources
void freeVector(Vector *vector) {
    free(vector->data);
    free(vector);
}

// Example usage
int main() {
    Vector *vector = createVector(4);
    
    vectorPushBack(vector, 10);
    vectorPushBack(vector, 20);
    vectorPushBack(vector, 30);
    
    printf("Element at index 0: %d\n", vectorGet(vector, 0));  // Output: 10
    printf("Element at index 1: %d\n", vectorGet(vector, 1));  // Output: 20
    printf("Element at index 2: %d\n", vectorGet(vector, 2));  // Output: 30
    
    freeVector(vector);
    return 0;
}
