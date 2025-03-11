#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct
{
    Node* top;
}Stack;

Stack* createStack(){
    Stack* newList = (Stack *)malloc(sizeof(Stack));
    newList->top = NULL;
    return newList;
}

Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *list,int data){
    if(list == NULL){
        printf("\nList Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = list->top;
    list->top = newNode;
}

int pop(Stack *list){
    int ele = list->top->data;
    list->top = list->top->next;
    return ele;
}

void display(Stack *list){

    if(list == NULL){
        printf("\nStack Is Not Created !!");
        return;
    }
    if(list->top == NULL){
        printf("\nStack Underflow !!");
        return;
    }
    Node *temp = list->top;
    printf("\n TOP \n");
    while (temp != NULL)
    {
        printf("\n|%d|\n____",temp->data);
        temp = temp->next;
    }
    // printf("NULL");
}
