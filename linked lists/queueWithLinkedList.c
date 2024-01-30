// implementing a queue using a singly linked list, where pop is O(1) and push is O(1).

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to adda node to the linked list
void addNode(struct Node** head_ref, struct Node* new_node) {
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete node from the linked list 
void listDelete(struct Node** head_ref, struct Node* x) {
    if (x->next != NULL) {
        x->data = x->next->data;
        x->next = x->next->next;
    } else {
        struct Node* current = (*head_ref);
        while (current->next->next != NULL) {
            current = current->next;
        }
        current->next = NULL;
    }
}

// Define the structure for a queue 
struct Queue {
    struct Node* front;
    struct Node* rear;
}; 

// Function to create a new queue 
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/*
In addition to the head, also keep a pointer to the last element in the linked
list. To enqueue, insert the element after the last element of the list, and set it
to be the new last element. To dequeue, delete the first element of the list and
return it.
*/

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL) {
        return 1;
    }
    return 0;
}

// Function to enqueue element into Queue
void enqueue(struct Queue* queue, int data) {
    struct Node* new_node = createNode(data);
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

// Function to dequeue element from Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int data = queue->front->data;
    listDelete(&(queue->front), queue->front);
    return data;
}