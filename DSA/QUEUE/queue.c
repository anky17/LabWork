#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct Queue
{
    int items[MAXSIZE];
    int front;
    int rear;
};

typedef struct Queue q;

void initialize(q *Q)
{
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty(q *Q)
{
    return (Q->front == -1);
}

int isFull(q *Q)
{
    return (Q->rear == MAXSIZE - 1);
}

void enqueue(q *Q, int value)
{
    if (isFull(Q))
    {
        printf("Queue is full!");
        return ;
    }
    if (isEmpty(Q))
    {
        Q->front = 0;
    }
    Q->rear++;
    Q->items[Q->rear] = value;
    printf("Enqueued %d.\n", value);
}

int dequeue(q *Q)
{
    int item;
    if (isEmpty(Q))
    {
        printf("Queue is empty!");
        return -1;
    }
    item = Q->items[Q->front];
    Q->front++;
    return item;
}

int main()
{
    struct Queue q;
    initialize(&q);
    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 3);

    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    return 0;
}