#include <stdio.h>
#include <omp.h>

#define N 3  

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int C[N][N];  

    double stime=omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    double etime=omp_get_wtime();


    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
printf("Total execution time = %f",etime-stime);
    return 0;
}
