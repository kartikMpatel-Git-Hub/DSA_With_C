#include "stdio.h"
#include "stdlib.h"

void main(){
    int n = 3;
    int *arr1 = (int *)calloc(n*n,sizeof(int));
    int *arr2 = (int *)calloc(n*n,sizeof(int));
    int *sum = (int *)calloc(n*n,sizeof(int));

    printf("\nEnter Array1");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("\nEnter Value For Arr1[%d][%d] : ",i,j);
            scanf("%d",(arr1 + i * n +  j));
        }
    }
    
    printf("\nEnter Array2");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("\nEnter Value For Arr2[%d][%d] : ",i,j);
            scanf("%d",(arr2 + i * n +  j));
        }
    }
    
    printf("\nCalculating...");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(sum + i * n + j) = *(arr1 + i * n + j) + *(arr2 + i * n + j);
        }
    }
    printf("\nSum Array\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t",*(sum + i * n + j));
        }
        printf("\n");
    }
}