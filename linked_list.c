#include "linked_list.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void PrintMyName()
{
    printf("Insert Your Number");
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

    // Print top borders
    while (temp != NULL) {
        printf("+-----+");
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");

    // Print data rows
    temp = head;
    while (temp != NULL) {
        printf("| %3d |", temp->data);
        if (temp->next != NULL) {
            printf("-");
        }
        temp = temp->next;
    }
    printf("\n");

    // Print bottom borders
    temp = head;
    while (temp != NULL) {
        printf("+-----+");
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void insertPrint(Node** head, int data) {
    insertAtEnd(head, data);
    printf("Inserted %d into the list.\n", data);
    printList(*head);
}

void deletePrint(Node** head, int key) {
    deleteNode(head, key);
    printf("Deleted %d from the list.\n", key);
    printList(*head);
}

