#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct
{
    int id;
    char *name;
    char *gender;
}Student;


typedef struct Node
{
    struct Node *prev;
    Student *student;
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

Student *createStrudent(int id,char *name,char *gender){
    Student *s = (Student*)malloc(sizeof(Student));
    s->id = id;
    s->name = (char*)calloc(7,sizeof(char));
    s->gender = (char*)calloc(7,sizeof(char));

    strcpy(s->name,name);
    strcpy(s->gender,gender);

    return s;
}

Node* createNode(int id,char *name,char *gender){
    struct Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->student = createStrudent(id,name,gender); 
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertFirst(LL *list,int id,char *name,char *gender){
    Node *newNode = createNode(id,name,gender);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        return;
    }
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
}

void insertLast(LL *list,int id,char *name,char *gender){
    
    Node *newNode = createNode(id,name,gender);
    if(list->head == NULL){
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
}
void displayStudent(Student *s){
    printf("\n\nId : %d",s->id);
    printf("\nName : %s",s->name);
    printf("\nGender : %s",s->gender);
}
void deleteFirst(LL *list){
    if(list->head == NULL){
        printf("List Is EMpty !!");
        return ;
    }
    if(list->head->next == NULL){
        displayStudent(list->head->student);
        printf("\nDeleted !!");
        list->head = list->tail =  NULL;
        return;
    }
    displayStudent(list->head->student);
    printf("\nDeleted !!");
    list->head = list->head->next;
    free(list->head->prev);
    list->head->prev = NULL;
}

void deleteLast(LL *list){
    if(list->head == NULL){
        printf("List Is EMpty !!");
        return;
    }
    if(list->head->next == NULL){
        displayStudent(list->head->student);
        printf("\nDeleted !!");
        list->head = list->tail = NULL;
        return;
    }
    displayStudent(list->head->student);
    printf("\nDeleted !!");
    Node *temp = list->head;
    while (temp->next != list->tail)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    list->tail = temp;
}

void sortList(LL *list){
    
    Node *outer = list->head;
    while (outer)
    {
        Node *inner = outer->next;
        Node *temp = outer;
        while (inner)
        {
            if(temp->student->id > inner->student->id){
                temp = inner;
            }
            inner = inner->next;
        }
        
        if(temp != outer){
            Student *  student = temp->student;
            temp->student = outer->student;
            outer->student = student;
        }
        outer = outer->next;
    }
    
}

void display(LL *list){
    if(list->head == NULL){
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->head;
    printf("\n\n");
    while(temp != NULL)
    {
        displayStudent(temp->student);
        temp = temp->next;
    }
    // while(temp != NULL);
    printf("\n\nNULL");
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
        displayStudent(temp->student);
        temp = temp->prev;
    }while(temp != NULL);
    printf("NULL");
}