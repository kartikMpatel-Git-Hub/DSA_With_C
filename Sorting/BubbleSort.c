#include "stdio.h"

void main(){
    int n = 5;
    int arr[] = {5,4,3,2,1};                     
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
}