#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    struct Node *prev;
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
    newNode->prev = NULL;
    return newNode;
}
void insertFirst(LL *list,int data){
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        return;
    }
    newNode->next = list->head;
    list->head->prev = newNode;
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
    newNode->prev = list->tail;
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
    free(list->head->prev);
    list->head->prev = NULL;
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
    while (temp->next != list->tail)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    list->tail = temp;
    return data;
}

void insertIdx(LL *list,int idx,int data){
    Node *newNode = createNode(data);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    if(idx == 0){
        insertFirst(list,data);
        return;
    }
    Node *temp = list->head;
    while (idx > 1 && temp->next != NULL)
    {
        temp = temp->next;
        idx--;
    }
    if(temp->next == NULL){
        insertLast(list,data);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

//

void sortList(LL *list){
    if(list == NULL){
        printf("\nList Is Empty !!");
        return;
    }
    if(list->head == NULL){
        printf("\nList Is EMpty !");
        return;
    }
    if(list->head->next == NULL){
        return;
    }
    Node *outer = list->head;
    while (outer != NULL)
    {
        Node *inner = outer->next;
        Node *temp = outer;
        while (inner != NULL)
        {   
            if(temp->data > inner->data){
                temp = inner;
            }
            inner = inner->next;
        }
        int data = temp->data;
        temp->data = outer->data;
        outer->data = data;
        outer = outer->next;
    }
    
}
Node* midNode(Node *start,Node *end){
    if(start == NULL){
        return NULL;
    } 
    if(start->next == NULL){
        return start;
    }
    Node *slow = start;
    Node *fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}
int searchNode(LL *list,int key){
    if(list == NULL){
        printf("\nList Is Empty !!");
        return -1;
    }
    if(list->head == NULL){
        printf("\nList Is EMpty !");
        return -1;
    }
    Node *start = list->head;
    Node *end = list->tail;
    Node *mid = NULL;
    while(start != end){
        mid = midNode(start,end);
        if(mid->data == key){
            printf("\nValue Founded !!");
            return mid->data;
        }
        else if(mid->data > key){
            end = mid;
        }
        else{
            start = mid->next;
        }
    }
    if(mid->next->data == key){
        printf("\nValue Founded !");
        return mid->next->data;
    }
    printf("\nValue Not Founded !");
    return -1;
}
//
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
    }while(temp != NULL);
    printf("NULL");
}
void displayRev(LL *list){
    if(list->head == NULL){
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->tail;
    printf("\nReverser \n");
    do
    {
        printf("%d -> ",temp->data);
        temp = temp->prev;
    }while(temp != NULL);
    printf("NULL");
}

Node *reverse(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    
    Node *newHead = reverse(temp);
    temp->next = head;
    return newHead;
}

void reveserList(LL *list){
    list->tail = list->head;
    list->head = reverse(list->head);
    list->head->prev = NULL;
}