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
    return q->front == -1;
}

int isFUll(Queue *q){
    return (q->rear+1) % q->size == q->front;
}

int removeLast(Queue *q){
    if(isEmpty(q)){
        printf("Queue Is Empty !");
        return -1;
    }
    int data = q->data[q->rear];
    q->rear--;
    if(q->rear == -1){
        q->front = -1;
    }
    return data;
}
void enQueue(Queue* q,int data){
    if(isFUll(q)){
        printf("\nFront : %d",q->rear);
        printf("\nQueue Is Full !");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = data;
}

int deQueue(Queue *q){
    if(isEmpty(q)){
        printf("\nQueue Is Empty !");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    if(q->front == (q->rear+1) % q->size)
        q->front = q->rear = -1;
    return data;
}
void insertFront(Queue *q,int data){
    if(q->front == 0){
        printf("No Space Available !!");
        return;
    }
    if(q->front == -1){
        enQueue(q,data);
        return;
    }
    q->front--;
    q->data[q->front] = data;
}
void display(Queue *q){

    printf("\n\n");
    if(isEmpty(q)){
        printf("\nQueue Is Empty Display!");
        return;
    }
    int i = q->front;
    while(1){
        printf("%d\t",q->data[i]);
        if(i == q->rear){
            return;
        }
        i = (i + 1) % q->size;
    }
    
    
}

void main(){
    Queue *q = createQueue(5);
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);


    display(q);
    
    printf("\nDeleted  : %d\n\n",deQueue(q));
    // printf("\nDeleted  : %d\n\n",removeLast(q));
    // printf("\nDeleted  : %d\n\n",removeLast(q));
    // printf("\nDeleted  : %d\n\n",removeLast(q));
    // printf("\nDeleted  : %d\n\n",removeLast(q));

    insertFront(q,100);
    display(q);

}
