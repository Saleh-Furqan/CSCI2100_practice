#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// searching linked list CLRS1
struct Node* listSearch(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

// prepending into linked list CLRS2
void listPrepend(struct Node** head_ref, struct Node* new_node) {
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// inserting into linked list CLRS3
void listInsert(struct Node* x, struct Node* y) {
    x->next = y->next;
    x->prev = y;
    if (y->next != NULL) {
        y->next->prev = x;
    }
    y->next = x;
}

// deleting from linked list CLRS4
void listDelete(struct Node** head_ref, struct Node* x) {
    if (x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        (*head_ref) = x->next;
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    }
}


int main() {
    // Create the head node
    struct Node* head = createNode(1);

    // Create additional nodes
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    // Link the nodes together
    head->next = second;
    second->next = third;
    second->prev = head;
    third->prev = second;

    // Traverse the linked list and print the data
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
