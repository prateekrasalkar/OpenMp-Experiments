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

    start = omp_get_wtime();

  
    for (int step = 1; step < N; step *= 2) {
        #pragma omp parallel for
        for (int i = step; i < N; i++) {
            result[i] = arr[i] + arr[i - step];
        }
      
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            arr[i] = result[i];
        }
    }

    end = omp_get_wtime();

    printf("Prefix Sum Computation Completed in %f seconds.\n", end - start);

  
    printf("Prefix Sum: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", result[i]);
    }
    printf("...\n");

    return 0;
}
