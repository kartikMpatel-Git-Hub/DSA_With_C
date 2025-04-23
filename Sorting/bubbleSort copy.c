#include "stdio.h"
#include "stdlib.h"

void swap(int *n1,int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = *n1;
}

void main(){
    int arr[] = {9,8,7,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n\n");
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }

}