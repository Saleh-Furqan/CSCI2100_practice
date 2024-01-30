// creating a dequeue 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a dequeue
struct Deque {
    int head;
    int tail;
    int capacity;
    int* array;
};

// Function to create a new dequeue
struct Deque* createDequeue(int capacity) {
    struct Deque* dequeue = (struct Deque*)malloc(sizeof(struct Deque));
    dequeue->head = 0;
    dequeue->tail = 0;
    dequeue->capacity = capacity;
    dequeue->array = (int*)malloc(dequeue->capacity * sizeof(int));
    return dequeue;
}

// Function to check if the dequeue is empty CLRS1
bool isEmpty(struct Deque* deque) {
    if (deque->head == deque->tail) {
        return true;
    }
    return false;
}

// Function to check if the dequeue is full CLRS2
bool isFull(struct Deque* deque) {
    if (deque->head == deque->tail + 1) {
        return true;
    }
    return false;
}

// Function to enqueue element from beginning (head-enqueue) into deque
void headEnqueue(struct Deque* D, int x) {
    if (isFull(D)) {
        printf("Deque overflow\n");
        return;
    }
    D->head = x;
    if (D->head == 1) {
        D->head = D->capacity;
    } else {
        D->head--;
    }
}

// Function to enqueue element from end (tail-enqueue) into deque
void tailEnqueue(struct Deque* D, int x) {
    if (isFull(D)) {
        printf("Deque overflow\n");
        return;
    }
    D->array[D->tail] = x;
    if (D->tail == D->capacity) {
        D->tail = 1;
    } else {
        D->tail++;
    }
}

// Function to dequeue element from beginning (head-dequeue) out of deque
void headDequeue(struct Deque* D) {
    if (isEmpty(D)) {
        printf("Deque underflow\n");
        return;
    }
    int x = D->array[D->head];
    if (D->head == D->capacity) {
        D->head = 1;
    } else {
        D->head++;
    }
    return x;
}

// Function to dequeue element from end (tail-dequeue) out of deque
void tailDequeue(struct Deque* D) {
    if (isEmpty(D)) {
        printf("Deque underflow\n");
        return;
    }
    int x = D->array[D->tail];
    if (D->tail == 1) {
        D->tail = D->capacity;
    } else {
        D->tail--;
    }
    return x;
}