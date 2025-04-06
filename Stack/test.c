#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    int** array = (int**)malloc(rows * sizeof(int));
    int* column = (int*)malloc(rows * sizeof(int));

    for (i = 0; i < rows; i++) {
        int cols;
        printf("Enter the number of columns for row %d: ", i + 1);
        scanf("%d", &cols);

        array[i] = (int*)malloc(cols * sizeof(int));
        column[i] = cols;
        printf("Enter %d elements for row %d: ", cols, i + 1);
        for (j = 0; j < cols; j++)
            scanf("%d", &array[i][j]);
    }
    printf("\nRagged Array:\n");
    for (i = 0; i < rows; i++) {
        for(int j = 0; j < column[i]; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}