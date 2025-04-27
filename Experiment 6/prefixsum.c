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




#include <stdio.h>
#include <omp.h>

int main() {
    int N = 5;
    int arr[N], result[N];
    double start, end;

    // Initialize array
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    start = omp_get_wtime();

    // Compute prefix sum sequentially
    result[0] = arr[0];
    for (int i = 1; i < N; i++) {
        result[i] = result[i - 1] + arr[i];
    }

    end = omp_get_wtime();

    printf("Final Prefix Sum: %d\n", result[N - 1]);
    printf("Serial Prefix Sum Computation Time: %f seconds.\n", end - start);

    return 0;
}
