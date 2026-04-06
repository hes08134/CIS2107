//Eunseo Hwang Feb 15 CIS 2107
//Lab 5 2D Arrays
//print 2D arrays (find max value and sum of rows and columns, check if array is square, and display 2D array)

#include <stdio.h>

    int max(int row, int column, int arr[row][column]);
    int rowSum(int row, int column, int arr[row][column], int rowIndex);
    int columnSum(int row, int column, int arr[row][column], int columnIndex);
    void isSquare(int row, int column);
    void displayOutputs(int row, int column, int arr[row][column]);

int main(void) {
    int row;
    int column;

    puts("Let's create a 2Dim array!");

    printf("How many rows?\n");
    scanf("%d", &row);
    printf("How many columns?\n");
    scanf("%d", &column);

    int arr[row][column];
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            printf("Enter the [%u][%u]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    puts("");

    for (unsigned int i = 0; i < row; i++) {
        printf("Sum of the row %u = %u\n", i + 1, rowSum(row, column, arr, i));
    }

    puts("");

    for (unsigned int j = 0; j < column; j++) {
        printf("Sum of the column %u = %u\n", j + 1, columnSum(row, column, arr, j));
    }
    puts("");

    isSquare(row, column);
    displayOutputs(row, column, arr);

    puts("");
    printf("Max: %d\n", max(row, column, arr));

}

int max(int row, int column, int arr[row][column]) {
    int maxValue = arr[0][0];
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < column; j++) {
            if (maxValue < arr[i][j]) {
                maxValue = arr[i][j];
            }
        }
    }
    return maxValue;
}

int rowSum(int row, int column, int arr[row][column], int rowIndex) {
    int sum = 0; 

    for (unsigned int i = 0; i < column; i++) {
        sum += arr[rowIndex][i];
    }
    return sum;
}

int columnSum(int row, int column, int arr[row][column], int columnIndex) {
    int sum = 0;

    for (unsigned int i = 0; i < row; i++) {
        sum += arr[i][columnIndex];
    }
    return sum;
}

void isSquare(int row, int column) {
    if (row == column) {
        puts("This is a square array\n");
    } else {
        puts("This is not a square array\n");
    }
}

void displayOutputs(int row, int column, int arr[row][column]) {
    puts("Here is your 2Dim array: ");

    for (unsigned int i = 0; i < row; i++) {
        printf("[");
        for (unsigned int j = 0; j < column; j++) {
            printf("%d", arr[i][j]);
            if (j < column - 1) {
                printf(", ");
            }
        }
        puts("]");
    }
}