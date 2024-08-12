#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

HashNode* hashTable[SIZE];

unsigned int hashFunction(int key) {
    return key % SIZE;
}

void insertHashTable(int key, int value) {
    unsigned int hashIndex = hashFunction(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        HashNode* temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int searchHashTable(int key) {
    unsigned int hashIndex = hashFunction(key);
    HashNode* temp = hashTable[hashIndex];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;  // Return -1 if key not found
}
