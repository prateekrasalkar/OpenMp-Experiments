#include <stdio.h>
#include <omp.h>

int main() {
	int N = 1000;
    int arr[N], result[N];
    double start, end;
    
    
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1; 
    }
    
    result[0] = arr[0];
    
    start = omp_get_wtime();
    
    #pragma omp parallel for
    for (int i = 1; i < N; i++) {
        result[i] = result[i - 1] + arr[i];
    }
    end = omp_get_wtime();
    printf("Prefix Sum Computation Completed in %f seconds.\n", end - start);
    return 0;
}

