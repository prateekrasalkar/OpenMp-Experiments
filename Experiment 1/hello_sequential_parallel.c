#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads = 4;  
    printf("Sequential Execution:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("Hello, World from iteration %d\n", i);
    }

    printf("\nParallel Execution:\n");
    #pragma omp parallel num_threads(num_threads)
    {
        int id = omp_get_thread_num();
        printf("Hello, World from thread %d\n", id);
    }

    return 0;
}
