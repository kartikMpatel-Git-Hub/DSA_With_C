#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int* data;
    int front;
    int rear;
    int size;
}Queue;

Queue* createQueue(int size){
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->data = (int *)calloc(size,sizeof(int));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = size;
    return newQueue;
}

int isEmpty(Queue *q){
    return q->rear == -1 || q->front > q->rear;
}

int isFUll(Queue *q){
    return q->rear == q->size-1;
}


void enQueue(Queue* q,int data){
    if(isFUll(q)){
        printf("\nQueue Is Full !");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->data[++q->rear] = data;
}

int deQueue(Queue *q){
    if(isEmpty(q)){
        printf("\nQueue Is Empty !");
        return -1;
    }
    int data = q->data[q->front];
    q->front++;
    return data;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("\nQueue Is Empty !");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d\t",q->data[i]);
    }
}

void main(){
    Queue *q = createQueue(5);
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);
    enQueue(q,50);

    display(q);
    
    printf("\n\nDeleted  : %d\n\n",deQueue(q));
    printf("\n\nDeleted  : %d\n\n",deQueue(q));
    printf("\n\nDeleted  : %d\n\n",deQueue(q));
    printf("\n\nDeleted  : %d\n\n",deQueue(q));
    // printf("\n\nDeleted  : %d\n\n",deQueue(q));

    display(q);
}
