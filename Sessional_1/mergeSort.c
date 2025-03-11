#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void merger(int *arr1,int n1,int *arr2,int n2,int *newArr){
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j]){
            newArr[k] = arr1[i];
            i++;
        }
        else{
            newArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        newArr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        newArr[k] = arr2[j];
        j++;
        k++;
    }  
}

int main(){

    int arr1[] = {3,4,6,10,11,15};
    int arr2[] = {1,5,8,12,14,19};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int *newArr = (int *)calloc(n1 + n2,sizeof(int));
    merger(arr1,n1,arr2,n2,newArr);
    for(int i = 0; i < n1+n2; i++){
        printf("%d\t",newArr[i]);
    }
}