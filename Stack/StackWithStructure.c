#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct 
{
    int *data;
    int size;
    int top;
}Stack;


int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}


int isFull(Stack *s){
    if((s->top+1) == s->size){
        return 1;
    }
    return 0;
}

void push(Stack *s,int ele){
    if(isFull(s)){
        printf("\nStack is Full !");
        return;
    }
    s->top++;
    s->data[s->top] = ele;
}

void peek(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return;
    }
    printf(" %d",s->data[s->top]);
}
void pop(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return;
    }
    s->top--;
}
void createStack(Stack *s){
    printf("\nENter Stack Size :");
    scanf("%d",&s->size);
    s->data = (int *)calloc(s->size,sizeof(int));
    s->top = -1;
}
int main(){

    Stack *s = (Stack *)calloc(1,sizeof(Stack));
    createStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    peek(s);
    pop(s);
    peek(s);
}