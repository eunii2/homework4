#include <stdio.h>
#include <stdlib.h>

//���� �Ҵ�� 2���� �迭�� �޸𸮿��� �����ϱ� ���� �Լ�
void free_matrix(int **matrix, int row){
    for(int i = 0; i < row; i++){ //�迭�� �� �࿡ ���� �ݺ�
        free(matrix[i]); //�� ���� �޸𸮿��� ����
    }
    free(matrix); //2���� �迭�� �޸𸮿��� ����
}

//2���� �迭�� ����ϱ� ���� �Լ�
void print_matrix(int **matrix, int row, int col){  
    printf("Matrix : \n");
    for(int i = 0; i < row; i++){ //�迭�� �� �࿡ ���� �ݺ�
        for(int j = 0; j < col; j++){ //�� ���� ���� ���� �ݺ�
            printf("%d ", matrix[i][j]); //�� ��Ҹ� ���
        }
        printf("\n");
    }
}

//2���� �迭 ���� ������ �����ϴ� �Լ�
void addition_matrix(int **matrix1, int **matrix2, int row, int col){
    printf("Addition Result : \n");
    int **result = (int**)malloc(sizeof(int *)*row); //��� ������ ���� 2���� int�� �迭 �����Ҵ�
    for(int i = 0; i < row; i++){ //���� ���� ��ŭ �ݺ�
        result[i] = (int *)malloc(sizeof(int)*col); //�� �ึ�� ���� ���� ��ŭ int�� �޸� �����Ҵ�
        for(int j = 0; j < col; j++){ //���� ���� ��ŭ �ݺ�
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //matrix1�� matrix2�� ������ ��ġ���� ���� ���� �� �迭 result�� ����
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row); //��� ������ ���� �����Ҵ��� �޸� ����
}

//2���� �迭 ���� ������ �����ϴ� �Լ�
void subtraction_matrix(int **matrix1, int **matrix2, int row, int col) {
    printf("Subtraction Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row); //��� ������ ���� 2���� int�� �迭 �����Ҵ�
    for (int i = 0; i < row; i++) { //���� ���� ��ŭ �ݺ�
        result[i] = (int *)malloc(sizeof(int) * col); //�� �ึ�� ���� ���� ��ŭ int�� �޸� �����Ҵ�
        for (int j = 0; j < col; j++) { //���� ���� ��ŭ �ݺ�
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row); //��� ������ ���� �����Ҵ��� �޸� ����
}

//2���� �迭�� ��ġ��ķ� ����� �Լ�
void transpose_matrix(int **matrix1, int row, int col) {
    printf("Transpose Result:\n");
    int **result = (int **)malloc(sizeof(int *) * col); //��ġ����� ������ 2���� �����Ҵ� �迭 ����
    for (int i = 0; i < col; i++) { //��ġ����� ����� ���� �ݺ���
        result[i] = (int *)malloc(sizeof(int) * row); //��ġ����� �� ���� �����Ҵ����� ����
        for (int j = 0; j < row; j++) { //��ġ����� �� ���Ҹ� ���ϱ� ���� �ݺ���
            result[i][j] = matrix1[j][i]; //��ġ����� i�� j�� ������ matrix1�� j�� i�� ���� ����
            printf("%d ", result[i][j]); //��ġ����� ���� ���
        }
        printf("\n");
    }
    free_matrix(result, col); //��ġ����� ������ �迭�� �����Ҵ� �޸� ����
}

// �� ��İ� ����� ũ�⸦ �Է� �ް�, ���� ������ �ϴ� �Լ�
void multiply_matrix(int **matrix1, int **matrix2, int row1, int col1, int col2) {
    printf("Multiplication Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row1); //��� ����� �޸� �Ҵ�
    for (int i = 0; i < row1; i++) { //��� ����� ���� �ݺ�
        result[i] = (int *)malloc(sizeof(int) * col2); //��� ����� ���� ũ�⸸ŭ �޸� �Ҵ�
        for (int j = 0; j < col2; j++) { //��� ����� ���� �ݺ�
            result[i][j] = 0; //��� ����� ���� �ʱ�ȭ
            for (int k = 0; k < col1; k++) { //�� ����� ������ ���� �ݺ���
                result[i][j] += matrix1[i][k] * matrix2[k][j]; //����� ���Ҹ� ���ؼ� ������
            }
            printf("%d ", result[i][j]); //��� ����� ���Ҹ� ���
        }
        printf("\n");
    }
    free_matrix(result, row1); //���� ����� ������ �迭�� �����Ҵ� �޸� ����
}

int main(){
    int row, col; //int�� row�� col ����

    printf("[----- [�ְ���] [2022078054] -----]\n\n"); //�̸�, �й� ���

    //��� �� ���� �Է� �ޱ�
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &row, &col);
    //��� A �Է� �ޱ�
    int **matrix_a = (int **)malloc(sizeof(int *) * row); //�Է� ���� ��� A�� �������� �Ҵ�
    for (int i = 0; i < row; i++) {
        matrix_a[i] = (int *)malloc(sizeof(int) * col); //�� �ึ�� ���� ����ŭ �������� �Ҵ�
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix A at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_a[i][j]); //�� ��Ҹ� �Է� ����
        }
    }

    //��� �� ���� �Է� �ޱ�
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &row, &col);
    //��� B �Է� �ޱ�
    int **matrix_b = (int **)malloc(sizeof(int *) * row); //�Է� ���� ��� B�� �������� �Ҵ�
    for (int i = 0; i < row; i++) {
        matrix_b[i] = (int *)malloc(sizeof(int) * col); //�� �ึ�� ���� ����ŭ �������� �Ҵ�
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix B at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_b[i][j]); //�� ��Ҹ� �Է� ����
        }
    }

    print_matrix(matrix_a, row, col); //�Է� ���� ��� A ���

    print_matrix(matrix_b, row, col); //�Է� ���� ��� B ���

    addition_matrix(matrix_a, matrix_b, row, col); //��� A�� B�� ���� ���

    subtraction_matrix(matrix_a, matrix_b, row, col); //��� A�� B�� ���� ���

    transpose_matrix(matrix_a, row, col); //��� A�� ��ġ ����� ���

    printf("Enter the number of columns for Matrix A and rows for Matrix B: ");
    int col1, row2;
    scanf("%d %d", &col1, &row2); // ��� A�� �� ������ ��� B�� �� ������ �Է� ����
    
    if (col1 != row2) {
        //��� A�� �� ������ ��� B�� �� ������ ���� ��쿡�� ��� ������ ������
        printf("Error: Cannot multiply Matrix A and B.\n");
    } 
    else {
        int **result = (int **)malloc(sizeof(int *) * row); //��� ����� ������ ���� ������ �迭�� ���� �Ҵ�
        for (int i = 0; i < row; i++) {
            result[i] = (int *)malloc(sizeof(int) * row2); //��� ����� �� �ึ��, ���� ������ŭ �޸� �Ҵ�
            for (int j = 0; j < row2; j++) {
                result[i][j] = 0; //��� ����� �� ��Ҹ� 0���� �ʱ�ȭ
                for (int k = 0; k < col1; k++) {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j]; //��� A�� i��° ��� ��� B�� j��° ���� ���� ���� ������
            }
        }
    }
    //��� ����� ����ϰ�, ���� �Ҵ��� �޸𸮸� ����
    multiply_matrix(matrix_a, matrix_b, row, col1, row2); //��� ����� ���
    free_matrix(result, row); //��� ����� �޸� ����
}

free_matrix(matrix_a, row); //matrix_a�� �޸� ����
free_matrix(matrix_b, row); //matrix_b�� �޸� ����

return 0;
}