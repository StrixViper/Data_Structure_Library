#include "queue.h"
#include <stdio.h>

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isFullQueue(Queue* q) {
    return q->rear == MAX - 1;
}

int isEmptyQueue(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, int item) {
    if (isFullQueue(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = item;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    return q->items[(q->front)++];
}
