#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <stdio.h>

// Function prototypes
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n);
void heapSort(int arr[], int n);
void printHeap(int arr[], int n);

// Function implementations (inline)

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printHeap(int arr[], int n) {
    int levels = 0;
    int totalNodes = 0;
    int nodesAtLevel = 1;

    // Calculate total levels
    while (totalNodes < n) {
        totalNodes += nodesAtLevel;
        nodesAtLevel *= 2;
        levels++;
    }

    // Print each level
    int index = 0;
    nodesAtLevel = 1;
    for (int level = 0; level < levels; level++) {
        int nodesInThisLevel = nodesAtLevel;

        // Print spaces before nodes
        for (int i = 0; i < (1 << (levels - 1 - level)) - 1; i++)
            printf("   ");

        // Print nodes with connections
        for (int node = 0; node < nodesInThisLevel && index < n; node++) {
            printf("%3d", arr[index++]);
            for (int i = 0; i < (1 << (levels - level)) - 1; i++)
                printf("   ");
        }

        printf("\n");

        // Print connections between nodes
        if (level < levels - 1) {
            for (int i = 0; i < nodesInThisLevel; i++) {
                if (i * 2 < nodesInThisLevel) {
                    // Print left connection
                    printf("%*s|", (1 << (levels - level - 1)) * 3 - 2, "");
                }
                if (i * 2 + 1 < nodesInThisLevel) {
                    // Print right connection
                    printf("---");
                }
            }
            printf("\n");
        }

        nodesAtLevel *= 2;
    }
}

#endif // HEAP_H_INCLUDED
