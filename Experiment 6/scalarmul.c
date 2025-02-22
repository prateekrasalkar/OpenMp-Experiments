#include <stdio.h>
#include <omp.h>

#define N 1000


int main() {
    int scalar = 2;
    int matrix[N][N];
    double start, end;
    
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }
    
    start = omp_get_wtime();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] *= scalar;
        }
    }
    end = omp_get_wtime();
    printf("Matrix-Scalar Multiplication Completed in %f seconds.\n", end - start);
    return 0;
}
