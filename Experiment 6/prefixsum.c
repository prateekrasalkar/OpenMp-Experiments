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
    int N = 1000000;
    int arr[N], serial_result[N], parallel_result[N];
    double start_serial, end_serial, start_parallel, end_parallel;

    // Initialize array
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    // --- Serial Prefix Sum ---
    start_serial = omp_get_wtime();

    serial_result[0] = arr[0];
    for (int i = 1; i < N; i++) {
        serial_result[i] = serial_result[i - 1] + arr[i];
    }

    end_serial = omp_get_wtime();

    // --- Parallel Prefix Sum ---
    start_parallel = omp_get_wtime();

    #pragma omp parallel
    {
        int i, tid, nthreads;
        int sum = 0;

        nthreads = omp_get_num_threads();
        tid = omp_get_thread_num();

        // Step 1: Each thread computes local prefix sum
        #pragma omp for schedule(static)
        for (i = 0; i < N; i++) {
            if (i == 0)
                parallel_result[i] = arr[i];
            else
                parallel_result[i] = parallel_result[i-1] + arr[i];
        }
    }

    end_parallel = omp_get_wtime();

    printf("Final Serial Prefix Sum: %d\n", serial_result[N - 1]);
    printf("Final Parallel Prefix Sum: %d\n", parallel_result[N - 1]);
    printf("\n");
    printf("Serial Prefix Sum Computation Time: %f seconds.\n", end_serial - start_serial);
    printf("Parallel Prefix Sum Computation Time: %f seconds.\n", end_parallel - start_parallel);

    return 0;
}
