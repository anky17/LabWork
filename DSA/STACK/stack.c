#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Define the stack structure
struct Stack {
    int items[MAXSIZE];
    int top;
};


// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAXSIZE - 1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push more items.\n");
    } else {
        stack->items[++stack->top] = item;
        printf("%d pushed to the stack\n", item);
    }
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; // Return a default value indicating an error
    } else {
        return stack->items[stack->top--];
    }
}

// Function to get the top item of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Return a default value indicating an error
    } else {
        return stack->items[stack->top];
    }
}

// Driver program to test the stack ADT
int main() {
    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, 20);
    push(&myStack, 15);
    //push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    //printf("Top element after pop: %d\n", peek(&myStack));

    return 0;
}
