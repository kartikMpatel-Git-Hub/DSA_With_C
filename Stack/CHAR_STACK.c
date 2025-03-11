#include "stdio.h"
#include "stdlib.h"

typedef struct{
    char *data;
    int top;
    int size;
}STACK;

STACK* createStack(int size){
    STACK *s = (STACK*)malloc(sizeof(STACK));
    s->data = (char*)calloc(size,sizeof(char));
    s->top = -1;
    s->size = size;
    return s;
}

int isFullStack(STACK *s){
    return (s->top == s->size-1);
}

int isEmptyStack(STACK *s){
    return (s->top == -1);
}

void push(STACK *s,int ele){
    if(isFullStack(s)){
        printf("\nStack Is Full !");
        return;
    }
    s->data[++s->top] = ele; 
}

char pop(STACK *s){
    if(isEmptyStack(s)){
        printf("\nStack Is Empty !");
        return '\0';
    }

    return s->data[s->top--];
}

char peek(STACK *s){
    if(isEmptyStack(s)){
        printf("\nStack Is Empty !");
        return '\0';
    }
    return s->data[s->top];
}

void displayStack(STACK *s){
    printf("\n\n");
    for(int i = s->top; i >= 0; i--){
        printf("%c\t",s->data[i]);
    }
}