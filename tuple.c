#include "tuple.h"

// Function to create a tuple
Tuple* create_tuple(void* first, size_t first_size, void* second, size_t second_size) {
    Tuple* tuple = (Tuple*)malloc(sizeof(Tuple));
    if (!tuple) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tuple->first = malloc(first_size);
    tuple->second = malloc(second_size);
    if (!tuple->first || !tuple->second) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(tuple->first, first, first_size);
    memcpy(tuple->second, second, second_size);
    tuple->first_size = first_size;
    tuple->second_size = second_size;
    return tuple;
}

// Function to get the first element of the tuple
void* get_first(Tuple* tuple) {
    return tuple->first;
}

// Function to get the second element of the tuple
void* get_second(Tuple* tuple) {
    return tuple->second;
}

// Function to print the tuple
void print_tuple(Tuple* tuple, void (*print_first)(void*), void (*print_second)(void*)) {
    printf("(");
    print_first(tuple->first);
    printf(", ");
    print_second(tuple->second);
    printf(")\n");
}

// Function to free the tuple
void free_tuple(Tuple* tuple) {
    free(tuple->first);
    free(tuple->second);
    free(tuple);
}
