#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct
{
    Node* head;
    Node* tail;
}SingleLinkedList;

SingleLinkedList* createList(){
    SingleLinkedList* newList = (SingleLinkedList *)malloc(sizeof(SingleLinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

Node* createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node)); 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(SingleLinkedList *list,int data){
    if(list == NULL){
        printf("\nList Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = list->head;
    if(list->head == NULL){
        list->tail = newNode;
    }
    list->head = newNode;
}

void insertLast(SingleLinkedList *list,int data){
    if(list == NULL){
        printf("\nList Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        return;
    }
    list->tail->next = newNode;
    list->tail = newNode;
}
void deleteLast(SingleLinkedList *list){
    if(list == NULL){
        printf("\nList Is Not Created !!");
        return;
    }
    Node *temp = list->head;
    
    if(temp->next == NULL){
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    list->tail = temp;
}

void deleteFirst(SingleLinkedList *list){
    list->head = list->head->next;
}
void display(SingleLinkedList *list){

    if(list == NULL){
        printf("\nList Is Not Created !!");
        return;
    }
    if(list->head == NULL){
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->head;
    printf("\n\n");
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}


Node* middleElement(SingleLinkedList *list)
{
    Node *slow = list->head;
    Node *fast = list->head;

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
int size(SingleLinkedList *list){
    Node *temp = list->head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void reverseLinkedList(SingleLinkedList *list){
    Node *prev = NULL;
    Node *curr = list->head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev; 
}

void swap(SingleLinkedList *list,int start,int end){

    if(start < 0 || end < 0 || start >= size(list) || end >= size(list)){
        printf("\n\nInvalid Index !!");
        return;
    }
    Node *last = list->head;
    Node *first = list->head;

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
    Node *helper = list->head;
    while (last->next != NULL)
    {   
        helper = helper->next;
        last = last->next;
    }

    int temp = helper->data;
    helper->data = first->data;
    first->data = temp;
}


void concatenate(SingleLinkedList *list1,SingleLinkedList *list2){
    Node *temp = list2->head;
    while (temp != NULL)
    {
        insertLast(list1,temp->data);
        temp = temp->next;
    }
}