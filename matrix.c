#include <stdio.h>
#include <stdlib.h>

//동적 할당된 2차원 배열을 메모리에서 해제하기 위한 함수
void free_matrix(int **matrix, int row){
    for(int i = 0; i < row; i++){ //배열의 각 행에 대해 반복
        free(matrix[i]); //각 행을 메모리에서 해제
    }
    free(matrix); //2차원 배열을 메모리에서 해제
}

//2차원 배열을 출력하기 위한 함수
void print_matrix(int **matrix, int row, int col){  
    printf("Matrix : \n");
    for(int i = 0; i < row; i++){ //배열의 각 행에 대해 반복
        for(int j = 0; j < col; j++){ //각 행의 열에 대해 반복
            printf("%d ", matrix[i][j]); //각 요소를 출력
        }
        printf("\n");
    }
}

//2차원 배열 덧셈 연산을 수행하는 함수
void addition_matrix(int **matrix1, int **matrix2, int row, int col){
    printf("Addition Result : \n");
    int **result = (int**)malloc(sizeof(int *)*row); //결과 저장을 위한 2차원 int형 배열 동적할당
    for(int i = 0; i < row; i++){ //행의 개수 만큼 반복
        result[i] = (int *)malloc(sizeof(int)*col); //각 행마다 열의 개수 만큼 int형 메모리 동적할당
        for(int j = 0; j < col; j++){ //열의 개수 만큼 반복
            result[i][j] = matrix1[i][j] + matrix2[i][j]; //matrix1과 matrix2의 각각의 위치에서 값을 더한 후 배열 result에 저장
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row); //결과 저장을 위해 동적할당한 메모리 해제
}

//2차원 배열 뺄셈 연산을 수행하는 함수
void subtraction_matrix(int **matrix1, int **matrix2, int row, int col) {
    printf("Subtraction Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row); //결과 저장을 위한 2차원 int형 배열 동적할당
    for (int i = 0; i < row; i++) { //행의 개수 만큼 반복
        result[i] = (int *)malloc(sizeof(int) * col); //각 행마다 열의 개수 만큼 int형 메모리 동적할당
        for (int j = 0; j < col; j++) { //열의 개수 만큼 반복
            result[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_matrix(result, row); //결과 저장을 위해 동적할당한 메모리 해제
}

//2차원 배열을 전치행렬로 만드는 함수
void transpose_matrix(int **matrix1, int row, int col) {
    printf("Transpose Result:\n");
    int **result = (int **)malloc(sizeof(int *) * col); //전치행렬을 저장할 2차원 동적할당 배열 생성
    for (int i = 0; i < col; i++) { //전치행렬을 만들기 위한 반복문
        result[i] = (int *)malloc(sizeof(int) * row); //전치행렬의 한 행을 동적할당으로 생성
        for (int j = 0; j < row; j++) { //전치행렬의 한 원소를 구하기 위한 반복문
            result[i][j] = matrix1[j][i]; //전치행렬의 i행 j열 원소의 matrix1의 j행 i열 원소 대입
            printf("%d ", result[i][j]); //전치행렬의 원소 출력
        }
        printf("\n");
    }
    free_matrix(result, col); //전치행렬을 저장한 배열의 동적할당 메모리 해제
}

// 두 행렬과 행렬의 크기를 입력 받고, 곱셈 연산을 하는 함수
void multiply_matrix(int **matrix1, int **matrix2, int row1, int col1, int col2) {
    printf("Multiplication Result:\n");
    int **result = (int **)malloc(sizeof(int *) * row1); //결과 행렬의 메모리 할당
    for (int i = 0; i < row1; i++) { //결과 행렬의 행을 반복
        result[i] = (int *)malloc(sizeof(int) * col2); //결과 행렬의 열의 크기만큼 메모리 할당
        for (int j = 0; j < col2; j++) { //결과 행렬의 열을 반복
            result[i][j] = 0; //결과 행렬의 원소 초기화
            for (int k = 0; k < col1; k++) { //두 행렬의 곱셈을 위한 반복문
                result[i][j] += matrix1[i][k] * matrix2[k][j]; //행렬의 원소를 곱해서 더해줌
            }
            printf("%d ", result[i][j]); //결과 행렬의 원소를 출력
        }
        printf("\n");
    }
    free_matrix(result, row1); //곱셈 결과를 저장한 배열의 동적할당 메모리 해제
}

int main(){
    int row, col; //int형 row와 col 선언

    printf("[----- [최가은] [2022078054] -----]");

    //행과 열 개수 입력 받기
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &row, &col);
    //행렬 A 입력 받기
    int **matrix_a = (int **)malloc(sizeof(int *) * row); //입력 받을 행렬 A를 동적으로 할당
    for (int i = 0; i < row; i++) {
        matrix_a[i] = (int *)malloc(sizeof(int) * col); //각 행마다 열의 수만큼 동적으로 할당
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix A at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_a[i][j]); //각 요소를 입력 받음
        }
    }

    //행과 열 개수 입력 받기
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &row, &col);
    //행렬 B 입력 받기
    int **matrix_b = (int **)malloc(sizeof(int *) * row); //입력 받을 행렬 B를 동적으로 할당
    for (int i = 0; i < row; i++) {
        matrix_b[i] = (int *)malloc(sizeof(int) * col); //각 행마다 열의 수만큼 동적으로 할당
        for (int j = 0; j < col; j++) {
            printf("Enter the value for Matrix B at row %d column %d: ", i + 1, j + 1);
            scanf("%d", &matrix_b[i][j]); //각 요소를 입력 받음
        }
    }

    print_matrix(matrix_a, row, col); //입력 받은 행렬 A 출력

    print_matrix(matrix_b, row, col); //입력 받은 행렬 B 출력

    addition_matrix(matrix_a, matrix_b, row, col); //행렬 A와 B의 합을 출력

    subtraction_matrix(matrix_a, matrix_b, row, col); //행렬 A와 B의 차를 출력

    transpose_matrix(matrix_a, row, col); //행렬 A의 전치 행렬을 출력

    printf("Enter the number of columns for Matrix A and rows for Matrix B: ");
    int col1, row2;
    scanf("%d %d", &col1, &row2); // 행렬 A의 열 개수와 행렬 B의 행 개수를 입력 받음
    
    if (col1 != row2) {
        //행렬 A의 열 개수와 행렬 B의 행 개수가 같은 경우에만 행렬 곱셈을 수행함
        printf("Error: Cannot multiply Matrix A and B.\n");
    } 
    else {
        int **result = (int **)malloc(sizeof(int *) * row); //결과 행렬을 저장할 이중 포인터 배열을 동적 할당
        for (int i = 0; i < row; i++) {
            result[i] = (int *)malloc(sizeof(int) * row2); //결과 행렬의 각 행마다, 열의 개수만큼 메모리 할당
            for (int j = 0; j < row2; j++) {
                result[i][j] = 0; //결과 행렬의 각 요소를 0으로 초기화
                for (int k = 0; k < col1; k++) {
                    result[i][j] += matrix_a[i][k] * matrix_b[k][j]; //행렬 A의 i번째 행과 행렬 B의 j번째 열을 곱한 값을 더해줌
            }
        }
    }
    //결과 행렬을 출력하고, 동적 할당한 메모리를 해제
    multiply_matrix(matrix_a, matrix_b, row, col1, row2); //결과 행렬을 출력
    free_matrix(result, row); //결과 행렬의 메모리 해제
}

free_matrix(matrix_a, row); //matrix_a의 메모리 해제
free_matrix(matrix_b, row); //matrix_b의 메모리 해제

return 0;
}