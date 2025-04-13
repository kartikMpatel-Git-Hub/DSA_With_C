#include "stdio.h"

int main(){
    int n = 10;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i * 2;
    }
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    int key = 16;
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == key){
            printf("\n\nElement Is Found At Index %d",mid);
            return 0;
        }
        
        if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    // int flag = -1;
    // int idx = -1;
    // for(int i = 0; i < n; i++){
    //     if(arr[i] == key){
    //         flag = 1;
    //         idx = i;
    //         break;
    //     }
    // }
    // if(flag){
    //     printf("Element Found ! %d",idx);
    // }

}