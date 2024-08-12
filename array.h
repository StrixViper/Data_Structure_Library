#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

typedef struct {
    int* array;
    int used;
    int size;
} DynamicArray;

DynamicArray* createArray(int initialSize);
void insertArray(DynamicArray* a, int element);
void freeArray(DynamicArray* a);
void printArray(DynamicArray* a);
void deleteFromArray(DynamicArray* a, int index);
void insertPrint(DynamicArray* a, int element);
void deletePrint(DynamicArray* a, int index);

//--------------------#

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

void deleteFromArray(DynamicArray* a, int index) {
    if (index < 0 || index >= a->used) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < a->used - 1; i++) {
        a->array[i] = a->array[i + 1];
    }
    a->used--;
}

void deletePrint(DynamicArray* a, int index) {
    int item = a->array[index];  // Store the item to print it
    deleteFromArray(a, index);
    printf("Item %d Been Removed\n", item);
    printArray(a);  // Print the array after deletion
}


void insertPrint(DynamicArray* a, int element) {
    insertArray(a, element);
    printf("Item %d Been Added\n", element);
    printArray(a);  // Print the array after insertion
}

#endif // ARRAY_H_INCLUDED
