#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct
{
    Node *head;
    Node *tail;
}LL;

LL* createList(){
    LL *list = (LL*)malloc(sizeof(LL));
    list->head = NULL;
    list->tail = NULL;

    return list;
}
Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFirst(LL *list,int data){
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    newNode->next = list->head;
    list->tail->next = newNode;
    list->head = newNode;
}

void insertLast(LL *list,int data){
    
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    list->tail->next = newNode;
    newNode->next = list->head;
    list->tail = newNode;
}

int deleteFirst(LL *list){
    if(list->head == NULL){
        printf("List Is EMpty !!");
        return -1;
    }
    if(list->head->next == NULL){
        list->head = list->tail =  NULL;
        return -1;
    }
    int data = list->head->data;
    list->head = list->head->next;
    list->tail->next = list->head;
    return data;
}

int deleteLast(LL *list){
    if(list->head == NULL){
        printf("List Is EMpty !!");
        return -1;
    }
    if(list->head->next == NULL){
        list->head = list->tail = NULL;
        return -1;
    }
    int data = list->tail->data;
    Node *temp = list->head;
    while (temp->next->next != list->head)
    {
        temp = temp->next;
    }
    temp->next = list->head;
    list->tail = temp;
    free(temp->next);
    return data;
}
void display(LL *list){
    if(list->head == NULL){
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->head;
    printf("\n\n");
    do
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp != list->head);
    printf("HEAD");
}