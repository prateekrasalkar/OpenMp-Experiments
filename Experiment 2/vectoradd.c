#include <stdio.h>
#include <omp.h>

int main() {
    int vec[5] = {1, 2, 3, 4, 5};
    int scalar = 10;
    double start, end, serial_time, parallel_time;

    // Serial version
    start = omp_get_wtime();
    for (int i = 0; i < 5; i++) {
        vec[i] += scalar;
    }
    end = omp_get_wtime();
    serial_time = end - start;

    // Reset vector
    int vec2[5] = {1, 2, 3, 4, 5};

    // Parallel version
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < 5; i++) {
        vec2[i] += scalar;
    }
    end = omp_get_wtime();
    parallel_time = end - start;

    // Print speedup
    printf("Serial Time   = %f sec\n", serial_time);
    printf("Parallel Time = %f sec\n", parallel_time);
    printf("Speedup       = %f\n", serial_time / parallel_time);

    return 0;
}
