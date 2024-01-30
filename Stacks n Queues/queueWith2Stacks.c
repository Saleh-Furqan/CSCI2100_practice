// Creating a Queue using 2 Stacks

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a stack 
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a new stack 
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = 0;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty CLRS1
bool isEmpty(struct Stack* stack) {
    if ( stack->top == 0) {
        return true;
    }
    return false;
}

// Function to check if the stack is full CLRS2
bool isFull(struct Stack* stack) {
    if (stack->top == stack->capacity) {
        return true;
    }
    return false;
}

// Function to push element into Stack 
void push(struct Stack* stack, int data) {
    if (stack->top == stack->capacity) {
        printf("Stack Overflow\n");
        return;
    } else {
        stack->top++;
        stack->array[stack->top] = data;
    }
}

// Function to pop element out of Stack 
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        stack->top--;
        return stack->array[stack->top + 1];
    }
}

/////////////// Queue using 2 Stacks ///////////////

// Define the structure for a queue
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        return true;
    }
    return false;
}

// Function to check is the queue is full
bool isFull(struct Queue* queue) {
    if (isFull(queue->stack1) && isFull(queue->stack2)) {
        return true;
    }
    return false;
}

// Function to enqueue element into queue 
void enqueue(struct Queue* Q, int x) {
    if (isFull(Q)) {
        printf("Queue overflow\n");
        return;
    }
    push(Q->stack1, x);
}

// Function to dequeue element out of queue
int dequeue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue underflow\n");
        return NULL;
    }

    if (isEmpty(Q->stack2)) {
        for (int i = 0; i < Q->stack1->top; i++) {
            push(Q->stack2, pop(Q->stack1));
        }
        pop(Q->stack2);
    }
}