#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q);
int isFullQueue(Queue* q);
int isEmptyQueue(Queue* q);
void enqueue(Queue* q, int item);
int dequeue(Queue* q);
void printQueue(Queue* q);
void enqueuePrint(Queue* q, int item);
int dequeuePrint(Queue* q);

//----------------------#

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

void enqueuePrint(Queue* q, int item) {
    if (isFullQueue(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = item;
    printf("Item %d Been Added \n", item);
    printQueue(q);  // Print the queue after enqueuing an item
}

int dequeuePrint(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[(q->front)++];
    printf("Item %d Been Removed \n", item);
    printQueue(q);  // Print the queue after dequeuing an item
    return item;
}

void printQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("|-------|\n");
        printf("| %3d   |\n", q->items[i]);
        printf("|-------|\n");
    }
    printf("\n");
}


#endif // QUEUE_H_INCLUDED
