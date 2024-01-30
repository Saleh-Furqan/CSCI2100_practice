// implementing a stack using a singly linked list, where pop is O(1) and push is O(1).

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

// Define the structure for a stack 
struct Stack {
    struct Node* top;
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

// Function to push element into Stack 
void push(struct Stack* stack, int data) {
    struct Node* new_node = createNode(data);
    addNode(&(stack->top), new_node);
}

// Function to pop element out of Stack 
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack->top->data;
    listDelete(&(stack->top), stack->top);
    return data;
}
