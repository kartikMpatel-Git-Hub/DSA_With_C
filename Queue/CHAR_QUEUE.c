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
    return (q->rear == q->size -1);
}

int isEmptyQueue(QUEUE *q){
    return (q->front == -1 || q->front > q->rear);
}

void enQueue(QUEUE *q,int ele){
    if(isFullQueue(q)){
        printf("\nQueue Is Full !");
        return;
    }
    if(q->rear == -1 && q->front == -1)
        q->front = 0;
    q->data[++q->rear] = ele; 
}

char deQueue(QUEUE *q){
    if(isEmptyQueue(q)){
        printf("\nQueue Is Empty !");
        return '\0';
    }
    return q->data[q->front++];
}

char frontQueue(QUEUE *q){
    return q->data[q->front];
}

void displayQueue(QUEUE *q){
    printf("\n\n");
    for(int i = q->front; i <= q->rear; i++){
        printf("%c\t",q->data[i]);
    }
}

void reSetQueue(QUEUE *q){
    q->front = -1;
    q->rear = -1;
}