#include "stdio.h"

int bubbleSort(int *arr,int n){
    int count = 0;            
    int flag = 1;
    for(int i = 0; i <= n && flag == 1; i++){
        flag = 0;
        for(int j = 0; j <= n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            count++;
        }
    }
    return count;
}