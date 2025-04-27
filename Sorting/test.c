#include "quickSort.c"
#include "MergeSort.c"
#include "BubbleSort.c"
#include "insertionSort.c"

void main(){
    // int arr[] = {9,1,8,2,3,7,4,6,5};
    // int arr[] = {19,10,72,26,55,54,35,42,81};
    // int arr[] = {5 ,3 ,8 ,6 ,2 ,7 ,4 ,1};
    int arr[] = {9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice;
    printf("\n1.Bubble Sort\t2.Insertion Sort\tMerge Sort\t4.Quick Sort");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);
    for(int i = 0; i < size; i++)
        printf("%d\t",arr[i]); 
    switch (choice)
    {
        case 1:
            printf("\n\nBubble Sort Itteration %d",bubbleSort(arr,size-1));
            break;
        case 2:
            printf("\n\nInsertion Sort Itteration %d",insertionSort(arr,size-1));
            break;
        case 3:
            printf("\n\nMerge Sort Itteration %d",mergeSort(arr,0,size-1));
            break;
        case 4:
            printf("\n\nQuick Sort Itteration %d",quickSort(arr,0,size-1));
            break;
        
        default:
            break;
    }
    printf("\n\n");
    for(int i = 0; i < size; i++)
        printf("%d\t",arr[i]);
    return;
}