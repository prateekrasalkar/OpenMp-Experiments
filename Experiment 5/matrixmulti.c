#include<stdio.h>
#include<omp.h>
#define N 500

int main(){
int A[N][N], B[N][N], C[N][N] = {0};
double start_time = omp_get_wtime();  
#pragma omp parallel for schedule(static)  
for (int i = 0; i < N; i++)  
    for (int j = 0; j < N; j++)  
        for (int k = 0; k < N; k++)  
            C[i][j] += A[i][k] * B[k][j];  
double end_time = omp_get_wtime();  
printf("Static Scheduling Execution Time: %f seconds\n", end_time - start_time);  

start_time = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++)
            C[i][j] += A[i][k] * B[k][j];
end_time = omp_get_wtime();
printf("Dynamic Scheduling Execution Time: %f seconds\n", end_time - start_time);

return 0;
}
