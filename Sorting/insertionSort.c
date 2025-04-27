#include "stdio.h"
#include "stdlib.h"

int insertionSort(int *arr,int size){
    int count = 0;
    for(int i = 1; i <= size; i++){
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp)
        {
            arr[j] = arr[j-1];
            j--;
            count++;
        }
        arr[j] = temp;
    }
    return count;
}
