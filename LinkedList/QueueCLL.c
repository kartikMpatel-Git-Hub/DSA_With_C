#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct
{
    Node *front;
    Node *rear;
}Queue;

Queue* createList(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}
Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFirst(Queue *queue,int data){
    Node *newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        queue->front->next = queue->front;
        return;
    }
    newNode->next = queue->front;
    queue->rear->next = newNode;
    queue->front = newNode;
}

void insertLast(Queue *queue,int data){
    
    Node *newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        queue->front->next = queue->front;
        return;
    }
    queue->rear->next = newNode;
    newNode->next = queue->front;
    queue->rear = newNode;
}

int deleteFirst(Queue *queue){
    if(queue->front == NULL){
        printf("\nQueue Is EMpty !!");
        return -1;
    }
    if(queue->front->next == NULL){
        queue->front = queue->rear =  NULL;
        return -1;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    queue->rear->next = queue->front;
    return data;
}

int deleteLast(Queue *queue){
    if(queue->front == NULL){
        printf("\nQueue Is EMpty !!");
        return -1;
    }
    if(queue->front->next == NULL){
        queue->front = queue->rear = NULL;
        return -1;
    }
    int data = queue->rear->data;
    Node *temp = queue->front;
    while (temp->next->next != queue->front)
    {
        temp = temp->next;
    }
    temp->next = queue->front;
    queue->rear = temp;
    free(temp->next);
    return data;
}
void display(Queue *queue){
    if(queue->front == NULL){
        printf("\nQueue Has No Elements !!");
        return;
    }
    Node *temp = queue->front;
    printf("\n\n");
    do
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp != queue->front);
    printf("HEAD");
}