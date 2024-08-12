#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int key);
void printList(Node* head);
void insertAndPrint(Node** head, int data);
void deleteAndPrint(Node** head, int key);

//------------------------#

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;

    // Print the top border of each box
    while (temp != NULL) {
        printf(" +-----+");
        if (temp->next != NULL) {
            printf("     ");  // Add space between boxes and arrows
        }
        temp = temp->next;
    }
    printf("\n");

    temp = head;
    // Print the data inside each box
    while (temp != NULL) {
        printf("| %3d | ---> ", temp->data);
        if (temp->next != NULL) {
              // Add space between boxes and arrows
        }
        temp = temp->next;
    }
    printf("\n");

    temp = head;
    // Print the bottom border of each box
    while (temp != NULL) {
        printf("+-----+");
        printf("      ");
        if (temp->next != NULL) {

            // Add space between boxes and arrows
        }
        temp = temp->next;
    }
    printf("\n");
}

void insertAndPrint(Node** head, int data) {
    insertAtEnd(head, data);
    printf("Inserted %d into the list.\n", data);
    printList(*head);
}

void deleteAndPrint(Node** head, int key) {
    deleteNode(head, key);
    printf("Deleted %d from the list.\n", key);
    printList(*head);
}

#endif // LINKED_LIST_H_INCLUDED
