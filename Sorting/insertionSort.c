#include "stdio.h"
#include "stdlib.h"

void main(){
    int arr[] = {5,1,2,4,3,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
    
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
}
