// create a stack 

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