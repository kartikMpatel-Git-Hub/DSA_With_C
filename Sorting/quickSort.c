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

void quickSort(int *arr,int left,int right){
    if(left < right){
        int pivot = partition(arr,left,right);

        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot + 1,right);
    }
}

void main(){
    // int arr[] = {9,1,8,2,3,7,4,6,5};
    int arr[] = {19,10,72,26,55,54,35,42,81};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++)
        printf("%d\t",arr[i]);
    quickSort(arr,0,size-1);
    printf("\n\n");
    for(int i = 0; i < size; i++)
        printf("%d\t",arr[i]);
}