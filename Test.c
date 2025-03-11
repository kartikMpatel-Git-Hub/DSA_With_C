#include "stdio.h"
#include "string.h"

int sum(int n1,int n2){
    return n1 + n2;
}

void main(){
    int n1 = 20,n2 = 20;
    int (*funtion)(int,int);
    funtion = sum;
    printf("%d",funtion(n1,n2));
}