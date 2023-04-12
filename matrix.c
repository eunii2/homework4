#include <stdio.h>
#include <stdlib.h>

void free_matrix(int **matrix, int row){
    for(int i = 0; i < row; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int row, int col){  
    printf("Matrix : \n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addition_matrix(int **matrix1, int **matrix2, int row, int col){
    printf("Addition Result : \n");
    int **result = (int**)malloc(sizeof(int *)*row);
    for(int i = 0; i < row; i++){
        result[i] = (int *)malloc(sizeof(int)*col);
        for(int j = 0; j < col; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row);
}

void subtraction_matrix(int **matrix1, int **matrix2, int row, int col) {
    printf("Subtraction Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        result[i] = (int *)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row);
}

void transpose_matrix(int **matrix1, int row, int col) {
    printf("Transpose Result:\n");
    int **result = (int **)malloc(sizeof(int *) * col);
    for (int i = 0; i < col; i++) {
        result[i] = (int *)malloc(sizeof(int) * row);
        for (int j = 0; j < row; j++) {
            result[i][j] = matrix1[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, col);
}

void multiply_matrix(int **matrix1, int **matrix2, int row1, int col1, int col2) {
    printf("Multiplication Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row1);
    for (int i = 0; i < row1; i++) {
        result[i] = (int *)malloc(sizeof(int) * col2);
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row1);
}

int main(){
    int row, col;

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &row, &col);
    int **matrix_a = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        matrix_a[i] = (int *)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix A at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &row, &col);
    int **matrix_b = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        matrix_b[i] = (int *)malloc(sizeof(int) * col);
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix B at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_b[i][j]);
        }
    }

    print_matrix(matrix_a, row, col);

    print_matrix(matrix_b, row, col);

    addition_matrix(matrix_a, matrix_b, row, col);

    subtraction_matrix(matrix_a, matrix_b, row, col);

    transpose_matrix(matrix_a, row, col);

    printf("Enter the number of columns for Matrix A and rows for Matrix B: ");
    int col1, row2;
    scanf("%d %d", &col1, &row2);
    if (col1 != row2) {
        printf("Error: Cannot multiply Matrix A and B.\n");
    } 
    else {
        int **result = (int **)malloc(sizeof(int *) * row);
        for (int i = 0; i < row; i++) {
            result[i] = (int *)malloc(sizeof(int) * row2);
            for (int j = 0; j < row2; j++) {
                result[i][j] = 0;
                for (int k = 0; k < col1; k++) {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    multiply_matrix(matrix_a, matrix_b, row, col1, row2);
    free_matrix(result, row);
}

free_matrix(matrix_a, row);
free_matrix(matrix_b, row);

return 0;
}