#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *stack1;  // Stack used for pushing elements
    int *stack2;  // Stack used for popping elements
    int top1;     // Top pointer for stack1
    int top2;     // Top pointer for stack2
    int maxSize;  // Maximum size of the stacks
} MyQueue;

// Function to create and initialize the queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->maxSize = 100;  // Define a fixed size for simplicity
    queue->stack1 = (int*)malloc(queue->maxSize * sizeof(int));
    queue->stack2 = (int*)malloc(queue->maxSize * sizeof(int));
    queue->top1 = -1;  // Initialize stack1 as empty
    queue->top2 = -1;  // Initialize stack2 as empty
    return queue;
}

// Push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 < obj->maxSize - 1) {
        obj->stack1[++obj->top1] = x;  // Push element onto stack1
    }
}

// Helper function to transfer elements from stack1 to stack2
void transferStack(MyQueue* obj) {
    while (obj->top1 >= 0) {
        obj->stack2[++obj->top2] = obj->stack1[obj->top1--];  // Move elements from stack1 to stack2
    }
}

// Pop the front element from the queue
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {  // If stack2 is empty, transfer elements from stack1
        transferStack(obj);
    }
    if (obj->top2 >= 0) {
        return obj->stack2[obj->top2--];  // Pop from stack2
    }
    return -1;  // Return -1 if the queue is empty
}

// Peek at the front element of the queue without removing it
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {  // If stack2 is empty, transfer elements from stack1
        transferStack(obj);
    }
    if (obj->top2 >= 0) {
        return obj->stack2[obj->top2];  // Return the top element from stack2
    }
    return -1;  // Return -1 if the queue is empty
}

// Check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);  // Queue is empty if both stacks are empty
}

// Free the memory allocated for the queue
void myQueueFree(MyQueue* obj) {
    free(obj->stack1);  // Free stack1 memory
    free(obj->stack2);  // Free stack2 memory
    free(obj);          // Free the queue structure
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
