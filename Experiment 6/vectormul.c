#include <stdio.h>
#include <omp.h>

int main() {
  int N = 1000;
    int matrix[N][N], vector[N], result[N];
    double start, end;
    
    
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j; 
        }
    }
    
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        vector[i] = i + 1; 
    }
    
    start = omp_get_wtime();
   
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
