#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX 100


typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int item);
int pop(Stack* s);
void printStack(Stack* s);
void pushPrint(Stack* s, int item);
int popPrint(Stack* s);
//-----------------------#


void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void pushPrint(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
    printf("Item %d Been Added \n",item);
    printStack(s);  // Print the stack after pushing an item
}

int popPrint(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    int item = s->items[(s->top)--];
    printf("Item %d Been Removed \n",item);
    printStack(s);  // Print the stack after popping an item
    return item;
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("|-------|\n");
        printf("| %3d   |\n", s->items[i]);
        printf("|-------|\n");
    }
    printf("\n");
}

#endif // STACK_H_INCLUDED
