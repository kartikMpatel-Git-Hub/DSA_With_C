#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct
{
    Node* front;
    Node* rear;
}Queue;

int isEmpty(Queue *q){
    return q->front == NULL; 
}

Queue* createQueue(){
    Queue* newqueue = (Queue *)malloc(sizeof(Queue));
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}

Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enQueue(Queue *queue,int data){
    if(queue == NULL){
        printf("\nQueue Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int deQueue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue Is Empty !");
        return -1;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->front = queue->rear = NULL;
    }
    return data;
}

void display(Queue *queue){

    if(queue == NULL){
        printf("\nqueue Is Not Created !!");
        return;
    }
    if(queue->front == NULL){
        printf("\nqueue Has No Elements !!");
        return;
    }
    Node *temp = queue->front;
    printf("\n\n");
    while (temp != NULL)
    {
        printf("%d <-- ",temp->data);
        temp = temp->next;
    }
    printf("END");
}


Node* middleElement(Queue *queue)
{
    Node *slow = queue->front;
    Node *fast = queue->front;

    while (fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast->next == NULL)
            return slow;
        if(fast->next->next == NULL)
            return slow->next;
    }
    printf("\n\nOuter !!");
    return slow;
}
int size(Queue *queue){
    Node *temp = queue->front;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void reverseLinkedqueue(Queue *queue){
    Node *prev = NULL;
    Node *curr = queue->front;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    queue->front = prev; 
}

void swap(Queue *queue,int start,int end){

    if(start < 0 || end < 0 || start >= size(queue) || end >= size(queue)){
        printf("\n\nInvalid Index !!");
        return;
    }
    Node *last = queue->front;
    Node *first = queue->front;

    while (end != 0)
    {
        last = last->next;
        end--;
    }
    while (start != 0)
    {
        first = first->next;
        start--;
    }
    Node *helper = queue->front;
    while (last->next != NULL)
    {   
        helper = helper->next;
        last = last->next;
    }

    int temp = helper->data;
    helper->data = first->data;
    first->data = temp;
}