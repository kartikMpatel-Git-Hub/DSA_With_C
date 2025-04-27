#include "stdio.h"
#include "stdlib.h"

int merge(int *arr,int left,int mid,int right){
    int size = right - left + 1;
    int newArr[size];
    int i = left,j = mid + 1,k = 0;
    int count = 0;
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            newArr[k] = arr[i];
            k++;
            i++;
        }
        else{
            newArr[k] = arr[j];
            k++;
            j++;
        }
        count++;
    }
    while(i <= mid){
        newArr[k] = arr[i];
        k++;
        i++;
        count++;
    }
    while(j <= right){
        newArr[k] = arr[j];
        k++;
        j++;
        count++;
    }
    for(int idx = 0; idx < size; idx++){
        arr[left + idx] = newArr[idx];
    }
    return count;
}
int mergeSort(int *arr,int left,int right){
    if(left >= right)
        return 0;
    int count = 0;
    int mid = (left + right) / 2;
    count += mergeSort(arr,left,mid);
    count += mergeSort(arr,mid+1,right);

    merge(arr,left,mid,right);
    return count + 1;
}
// void main(){
//     // int arr[] = {8,7,6,5,4,3,2,1};
//     int arr[] = {1,3,5,9,2,4,8,16};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int mid = size / 2;
//     for(int i = 0; i < size; i++){
//         printf("%d\t",arr[i]);
//     }
//     printf("\n\n");
//     // mergeSort(arr,0,size-1);
//     merge(arr,0,mid+1,size-1);
//     for(int i = 0; i < size; i++){
//         printf("%d\t",arr[i]);
//     }
// }