#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray* createArray(int initialSize) {
    DynamicArray* a = (DynamicArray*)malloc(sizeof(DynamicArray));
    a->array = (int*)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
    return a;
}

void insertArray(DynamicArray* a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int*)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(DynamicArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void printArray(DynamicArray* a) {
    for (int i = 0; i < a->used; i++) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}
