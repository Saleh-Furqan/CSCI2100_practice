// creating a queue

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