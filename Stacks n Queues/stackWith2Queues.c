// // Creating a Stack using 2 Queues

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a queue
struct Queue {
    int head;
    int tail;
    int capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = 0;
    queue->tail = 0;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty CLRS1
bool isEmpty(struct Queue* queue) {
    if (queue->head == queue->tail) {
        return true;
    }
    return false;
}

// Function to check if the queue is full CLRS2
bool isFull(struct Queue* queue) {
    if (queue->head == queue->tail + 1) {
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
    Q->array[Q->tail] = x;
    if (Q->tail == Q->capacity) {
        Q->tail = 1;
    } else {
        Q->tail++;
    }
}

// Function to dequeue element out of queue
int dequeue(struct Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue underflow\n");
        return NULL;
    }
    int x = Q->array[Q->head];
    if (Q->head == Q->capacity) {
        Q->head = 1;
    } else {
        Q->head++;
    }
    return x;
}

/////////////// Stack using 2 Queues ///////////////
/*
The following is a way of implementing a stack using two queues, where pop
takes linear time, and push takes constant time. The first of these ways, consists
of just enqueueing each element as you push it. Then, to do a pop, you dequque
each element from one of the queues and place it in the other, but stopping
just before the last element. Then, return the single element left in the original
queue
*/ 
struct Stack {
    struct Queue* queue1;
    struct Queue* queue2;
};

// Function to create a new stack 
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->queue1 = createQueue(capacity);
    stack->queue2 = createQueue(capacity);
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    if (isEmpty(stack->queue1) && isEmpty(stack->queue2)) {
        return true;
    }
    return false;
}

// Function to check if the stack is full 
bool isFull(struct Stack* stack) {
    if (isFull(stack->queue1) && isFull(stack->queue2)) {
        return true;
    }
    return false;
}

// Function to push element into Stack 
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    } else {
        enqueue(stack->queue1, data);
    }
}

// Function to pop element out of Stack 
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        while (stack->queue1->head != stack->queue1->tail - 1) {
            enqueue(stack->queue2, dequeue(stack->queue1));
        }
        int x = dequeue(stack->queue1);
        while (!isEmpty(stack->queue2)) {
            enqueue(stack->queue1, dequeue(stack->queue2));
        }
        return x;
    }
}

