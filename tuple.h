#ifndef TUPLE_H
#define TUPLE_H

#include <stdio.h>
#include <stdlib.h>

// Define the Tuple structure with two generic types
typedef struct {
    void* first;
    void* second;
    size_t first_size;
    size_t second_size;
} Tuple;

// Function to create a tuple
Tuple* create_tuple(void* first, size_t first_size, void* second, size_t second_size);

// Function to get the first element of the tuple
void* get_first(Tuple* tuple);

// Function to get the second element of the tuple
void* get_second(Tuple* tuple);

// Function to print the tuple
void print_tuple(Tuple* tuple, void (*print_first)(void*), void (*print_second)(void*));

// Function to free the tuple
void free_tuple(Tuple* tuple);

#endif // TUPLE_H
