#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    int prio;
    struct Node *next;
}Node;
typedef struct
{
    Node *front;
    Node *rear;
}Queue;

Queue* createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}
Node* createNode(int data,int priority){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->prio = priority;
    newNode->next = NULL;
    return newNode;
}
void enQueue(Queue *queue,int data,int priority){
    
    Node *newNode = createNode(data,priority);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        return;
    }
    Node *temp = queue->front;
    if(newNode->prio <= queue->front->prio){
        newNode->next = queue->front;
        queue->front = newNode;
        return;
    }
    while (temp->next != NULL && temp->next->prio <= newNode->prio)
    {   
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    if(temp == queue->rear){
        queue->rear = newNode;
    }
}

int deQueue(Queue *queue){
    if(queue->front == NULL){
        printf("List Is EMpty !!");
        return -1;
    }
    if(queue->front == queue->rear){
        int data = queue->front->data;
        queue->front = queue->rear = NULL;
        return data;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    return data;
}

void display(Queue *queue){
    if(queue->front == NULL){
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = queue->front;
    printf("\n\n");
    while (1)
    {
        printf("| %d |\t",temp->data);
        if(temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    printf("<---");
}