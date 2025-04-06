#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int size;
    int top;
    int *data;
}Stack;

int isEmpty(Stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
int isFull(Stack *s){
    if(s->top+1 == s->size)
        return 1;
    return 0;
}
void push(Stack* s,int data){
    if(isFull(s)){
        printf("\nOver FLow !");
        return;
    }
    s->data[s->top+1] = data;
    s->top++;
}
int peak(Stack* s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return -1;
    }
    return s->data[s->top];
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("\nStack Is Empty !");
        return -1;
    }
    return s->data[s->top--];
}
Stack* createStack(int size){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->data = (int *)malloc(s->size * sizeof(int));
    return s;
}
// int main(){
//     Stack *s1 = createStack();
//     Stack *s2 = createStack();

//     push(s1,10);
//     push(s1,20);
//     push(s1,30);
//     push(s1,40);
//     push(s2,1);
//     push(s2,2);
//     push(s2,3);
//     push(s2,4);

//     printf("\n%d",peak(s1));
//     printf("\n%d",peak(s2));
//     pop(s1);
//     pop(s2);
//     printf("\n%d",peak(s1));
//     printf("\n%d",peak(s2));
// }