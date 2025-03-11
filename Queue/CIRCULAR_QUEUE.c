#include "stdio.h"
#include "stdlib.h"

typedef struct{
    char *data;
    int front;
    int rear;
    int size;
}QUEUE;

QUEUE* createQueue(int size){
    QUEUE *q = (QUEUE*)malloc(sizeof(QUEUE));
    q->data = (char*)calloc(size,sizeof(char));
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

int isFullQueue(QUEUE *q){
    return ((q->rear+1) % q->size == q->front);
}

int isEmptyQueue(QUEUE *q){
    return (q->front == -1);
}

void enQueue(QUEUE *q,int ele){
    if(isFullQueue(q)){
        printf("\nQueue Is Full !");
        return;
    }
    if(q->front == -1)
        q->front = 0;
    q->rear = (q->rear+1) % q->size;
    q->data[q->rear] = ele; 
}

char deQueue(QUEUE *q){
    if(isEmptyQueue(q)){
        printf("\nQueue Is Empty !");
        return '\0';
    }
    char ch = q->data[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
    return ch;
}

char frontQueue(QUEUE *q){
    if(isEmptyQueue(q)){
        printf("\nQueue Is Empty !");
        return '\0';
    }
    return q->data[q->front];
}

void displayQueue(QUEUE *q){
    if(isEmptyQueue(q)){
        printf("\nQueue Is Empty !");
        return;
    }
    printf("\n\n");
    int i = q->front;
    while (1) {
        printf("%c ", q->data[i]);
        if (i == q->rear) 
            break;
        i = (i + 1) % q->size;
    }
}

void reSetQueue(QUEUE *q){
    q->front = -1;
    q->rear = -1;
}