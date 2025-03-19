#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int *data[2];
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data[0] = (int *)malloc(sizeof(int) * 5);
    q->data[1] = (int *)malloc(sizeof(int) * 5);
    q->front = -1;
    q->rear = -1;
    q->size = 5;

    return q;
}

void reSizeQueue(Queue *q)
{
    printf("\nResizeing!!");
    q->data[0] = (int *)realloc(q->data, q->size * 2 * sizeof(int));
    q->data[1] = (int *)realloc(q->data, q->size * 2 * sizeof(int));
    q->size *= 2;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}
int isFull(Queue *q)
{
    return q->rear == q->size - 1;
}
void enQueue(Queue *q, int data,int priority)
{
    if (isFull(q))
    {
        reSizeQueue(q);
    }
    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->data[0][0] = data;
        q->data[1][0] = priority;
        return ;
    }
    int i = q->rear;
    while (i >= q->front && priority < q->data[1][i])
    {
        q->data[0][i+1] = q->data[0][i];
        q->data[1][i+1] = q->data[1][i];
        i--;
    }
    q->data[0][i+1] = data;
    q->data[1][i+1] = priority;
    q->rear++;
    return;
}

// int deQueue(Queue *q)
// {
//     if (isEmpty(q))
//     {
//         printf("\nQueue Is Empty !!");
//         return -1;
//     }
//     int data = q->data[q->front];
//     q->front++;
//     return data;
// }

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is EMpty !!");
        return;
    }
    printf("\n\n");
    // printf("\nHello! %d \t %d ",q->front,q->rear);
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d\t", q->data[0][i]);
    }
}