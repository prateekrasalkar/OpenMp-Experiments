#include <stdio.h>
#include <omp.h>

int main() {
    int N = 1000;
    int matrix[N][N], vector[N], result[N];
    double start, end;

    // Initialize matrix with i + j using nested loop collapse
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }

    // Initialize vector with 1s
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        vector[i] = 1;
        result[i] = 0; // Initialize result vector to 0
    }

    start = omp_get_wtime();

    // Matrix-vector multiplication
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    end = omp_get_wtime();

    printf("Matrix-Vector Multiplication Completed in %f seconds.\n", end - start);

    return 0;
}
