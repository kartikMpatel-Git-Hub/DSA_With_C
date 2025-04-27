#include "stdio.h"
#include "stdlib.h"

int partition(int *arr,int start,int end){
    int left = start;
    int pivot = start;
    int right = end;
    while(left < right){
        
        while(left <= end && arr[left] <= arr[pivot]){
            left++;
        }
        while(right >= start && arr[right] > arr[pivot]){
            right--;
        }
        if(left < right)
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp; 
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = temp;
    
    return right;
}

int quickSort(int *arr,int left,int right){
    int countLeft = 0,countRight = 0;
    if(left < right){
        int pivot = partition(arr,left,right);
        countLeft = quickSort(arr,left,pivot-1);
        countRight = quickSort(arr,pivot + 1,right);
        return countLeft + countRight + 1;
    }
    return 0;
}
