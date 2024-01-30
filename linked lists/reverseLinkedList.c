// reversing a singly linked list 
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

// Function to reverse a linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = (*head);
    while (current != NULL) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}