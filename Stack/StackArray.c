#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int isEmpty(int top){
    if(top == -1){
        return 1;
    }
    return 0;
}

int isFull(int top,int n){
    if((top+1) == n){
        return 1;
    }
    return 0;
}

void push(int *arr,int ele,int *top,int n){
    if(isFull(*top,n)){
        printf("\nStack Is Full !");
        return;
    }
    arr[++*top] = ele;
}

void peek(int *arr,int top){
    if(isEmpty(top)){
        printf("\nStack Is Empty !");
        return;
    }
    printf("\n%d",arr[top]);
}
void pop(int *arr,int *top){
    if(isEmpty(*top)){
        printf("\nStack Is Empty !");
        return;
    }
    --*top;
}
int main(){

    int n = 5;
    int *arr = (int *)calloc(n,sizeof(int));
    int top = -1;
    push(arr,1,&top,n);
    push(arr,2,&top,n);
    push(arr,3,&top,n);
    push(arr,4,&top,n);
    push(arr,5,&top,n);
    push(arr,6,&top,n);

    peek(arr,top);
    pop(arr,&top);

    peek(arr,top);
    pop(arr,&top);

    peek(arr,top);
    pop(arr,&top);

    peek(arr,top);
    pop(arr,&top);

    peek(arr,top);
    pop(arr,&top);

    pop(arr,&top);
    peek(arr,top);
}