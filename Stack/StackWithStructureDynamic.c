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
        int newSize = s->size / 2;
        s->size += newSize;
        s->data = (int *)realloc(s->data,s->size * sizeof(int));
        printf("\n\nNew Size : %d",s->size);
        return 1;
    }
    return 0;
}

void push(Stack *s,int ele){
    if(isFull(s)){
        printf("\nStack Size Increased !");
    }
    s->top++;
    s->data[s->top] = ele;
}

void peek(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return;
    }
    printf("\n %d",s->data[s->top]);
}
void pop(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return;
    }
    s->top--;
}
void createStack(Stack *s){
    s->size = 5;
    s->data = (int *)calloc(s->size,sizeof(int));
    s->top = -1;
}
int main(){

    Stack *s = (Stack *)calloc(1,sizeof(Stack));
    createStack(s);
    for(int i = 0; i < 40; i++){
        push(s,i*2);
    }
    peek(s);
}