#include <stdio.h>
#include <omp.h>

int main() {
    int total_sum = 0;

    #pragma omp parallel
    {
        int partial_sum = 0;  // Each thread gets a private copy

        #pragma omp for
        for (int i = 1; i <= 20; i++) {
            partial_sum += i;  // Each thread computes a portion of the sum
        }

        #pragma omp atomic
        total_sum += partial_sum;  // Ensure correct accumulation
    }

    printf("Total Sum: %d\n", total_sum);  // Expected Output: 210
    return 0;
}

