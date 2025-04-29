#include <stdio.h>
#include <omp.h>

#define N 1000  // Size of the matrix

int main() {
    int scalar = 2;
    int matrix[N][N];
    double start, end;

    // Initialize matrix with i + j
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }

    start = omp_get_wtime();

    // Parallel matrix-scalar multiplication with thread info
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int thread_id = omp_get_thread_num();
            matrix[i][j] *= scalar;
            printf("Thread %d processing element [%d][%d]\n", thread_id, i, j);
        }
    }

    end = omp_get_wtime();
    printf("Matrix-Scalar Multiplication Completed in %f seconds.\n", end - start);

    return 0;
}
