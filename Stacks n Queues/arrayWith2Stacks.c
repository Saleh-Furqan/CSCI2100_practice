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

///////////////////// ArrayStack Implementation Starts From Here ////////////////////////

struct ArrayStack {
    struct Stack* stack1;
    struct Stack* stack2;
    int capacity;
    int* array;
};

// Function to create ArrayStack 
struct ArrayStack* createArrayStack(int capacity) {
    struct ArrayStack* arrayStack = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));

    arrayStack->stack1 = createStack(capacity);
    arrayStack->stack1->top = 0;

    arrayStack->stack2 = createStack(capacity);
    arrayStack->stack2->top = capacity - 1;

    arrayStack->capacity = capacity;
    arrayStack->array = (int*)malloc(arrayStack->capacity * sizeof(int));
    return arrayStack;
}

// Function to check if the ArrayStack is full CLRS1
bool isArrayStackFull(struct ArrayStack* arrayStack) {
    if (arrayStack->stack1->top == arrayStack->stack2->top + 1) {
        return true;
    }
    return false;
}

// Function to push element into ArrayStack 
void arrayStackPush(struct ArrayStack* arrayStack, struct Stack* stack, int data) {
    if (stack == arrayStack->stack1) {
        if (stack->capacity + 1 == arrayStack->stack2->top) {
            printf("ArrayStack Overflow\n");
            return;
        } else {
            arrayStack->stack1->top++;
            arrayStack->stack1->array[arrayStack->stack1->top] = data;
        }
    } else if (stack == arrayStack->stack2) {
        if (stack->capacity - 1 == arrayStack->stack1->top) {
            printf("ArrayStack Overflow\n");
            return;
        } else {
            arrayStack->stack2->top--;
            arrayStack->stack2->array[arrayStack->stack2->top] = data;
        }
    }
}

// Function to pop element out of ArrayStack
int arrayStackPop(struct ArrayStack* arrayStack, struct Stack* stack) {
    if (stack == arrayStack->stack1) {
        if (stack->top == 0) {
            printf("ArrayStack Underflow\n");
            return NULL;
        } else {
            arrayStack->stack1->top--;
            return arrayStack->stack1->array[arrayStack->stack1->top + 1];
        }
    } else if (stack == arrayStack->stack2) {
        if (stack->top == arrayStack->capacity - 1) {
            printf("ArrayStack Underflow\n");
            return NULL;
        } else {
            arrayStack->stack2->top++;
            return arrayStack->stack2->array[arrayStack->stack2->top - 1];
        }
    }
}
