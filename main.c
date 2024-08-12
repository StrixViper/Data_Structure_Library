#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "heap.h"
#include "graph.h"
#include "binary_tree.h"
#include "hash_table.h"
#include "array.h"




int main() {
    // Stack usage

    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Popped from stack: %d\n", pop(&s));

    // Queue usage
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Dequeued from queue: %d\n", dequeue(&q));

    // Linked list usage
    Node* head = NULL;

    insertAtEnd(&head,5);
    insertAtEnd(&head,10);


    // Heap usage
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Graph usage
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    printGraph(graph);

    // Binary tree usage
    // Insert nodes into the binary tree
    TreeNode* root = NULL;

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 31);
    insert(root, 21);
    insert(root, 41);
    insert(root, 71);
    insert(root, 61);
    insert(root, 81);

    // Perform inorder traversal
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\n");



    // Dynamic array usage
    DynamicArray* dynamicArray = createArray(2);
    insertArray(dynamicArray, 10);
    insertArray(dynamicArray, 20);
    insertArray(dynamicArray, 30);
    printArray(dynamicArray);
    freeArray(dynamicArray);

    // Hash table usage
    insertHashTable(1, 10);
    insertHashTable(2, 20);
    printf("Search key 1: %d\n", searchHashTable(1));
    printHashTable();

    return 0;
}
