#include <stdio.h>
#include <stdlib.h>

// Function to transpose a matrix
void transpose(double *input, double *output, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j * rows + i] = input[i * cols + j];
        }
    }
}

// Function to add two matrices
void add(double *matrix1, double *matrix2, double *result, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        result[i] = matrix1[i] + matrix2[i];
    }
}

// Function to multiply two matrices
void multiply(double *matrix1, double *matrix2, double *result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
        }
    }
}

// Function to print a matrix
void dump(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Function to reshape a matrix
void reshape(double *input, double *output, int old_rows, int old_cols, int new_rows, int new_cols) {
    if (old_rows * old_cols != new_rows * new_cols) {
        printf("Cannot reshape matrix: incompatible dimensions\n");
        return;
    }
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            output[i * new_cols + j] = input[i * new_cols + j];
        }
    }
}

int main() {
    // Example usage
    int rows = 3;
    int cols = 3;

    double matrix1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double matrix2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    double result[rows * cols];

    // Transpose
    double transposed[rows * cols];
    transpose(matrix1, transposed, rows, cols);
    printf("Transposed matrix:\n");
    dump(transposed, cols, rows);
    printf("\n");

    // Addition
    add(matrix1, matrix2, result, rows, cols);
    printf("Sum of matrices:\n");
    dump(result, rows, cols);
    printf("\n");

    // Multiplication
    multiply(matrix1, matrix2, result, rows, cols, cols);
    printf("Product of matrices:\n");
    dump(result, rows, cols);
    printf("\n");

    // Reshape
    int new_rows = 1;
    int new_cols = 9;
    double reshaped[new_rows * new_cols];
    reshape(matrix1, reshaped, rows, cols, new_rows, new_cols);
    printf("Reshaped matrix:\n");
    dump(reshaped, new_rows, new_cols);

    return 0;
}
