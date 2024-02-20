// WAP TO IMPLEMENT THE CIRCULAR QUEUE AS AN ADT.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Circular Queue Structure
typedef struct
{
    int front, rear;
    int capacity;
    int *array;
} CircularQ;

// Function to initialize the circular queue dynamically
void initializeQueue(CircularQ *queue, int capacity)
{
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int *)malloc(sizeof(int) * capacity);
}

// Function to check if the queue is empty
int isEmpty(CircularQ *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(CircularQ *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQ *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    // Increase rear circular queue pointer by 1 till it's size becomes equal to capacity-1
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;

    printf("%d enqueued to the circular queue.\n", data);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQ *queue)
{
    // Default value for an empty queue
    int data = -1;

    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        data = queue->array[queue->front];
        if (queue->front == queue->rear)
        {
            // If there is only one element in the queue
            queue->front = queue->rear = -1;
        }
        else
        {
            // After first element is dequeued point to next queue element.
            queue->front = (queue->front + 1) % queue->capacity;
        }

        printf("%d dequeued from the queue.\n", data);
    }

    return data;
}

// Function to display the elements in the circular queue
void displayQueue(CircularQ *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int i = queue->front;
        printf("Elements in the queue: ");
        do
        {
            printf("%d ", queue->array[i]);
            i = (i + 1) % queue->capacity;
        } while (i != (queue->rear + 1) % queue->capacity); // if i == last queue pointer i.e last queue element then loop terminates.
        printf("\n");
    }
}

// Function to free the memory allocated for the circular queue
void destroyQueue(CircularQ *queue)
{
    free(queue->array);
}

int main()
{
    CircularQ queue;
    initializeQueue(&queue, MAX_SIZE);

    enqueue(&queue, 11);
    enqueue(&queue, 12);
    enqueue(&queue, 13);
    enqueue(&queue, 14);
    enqueue(&queue, 15);
    displayQueue(&queue);

    dequeue(&queue);
    displayQueue(&queue);

    enqueue(&queue, 16);
    displayQueue(&queue);

    destroyQueue(&queue);

    return 0;
}
