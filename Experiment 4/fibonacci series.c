#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Fibonacci function using recursion with memoization
int fib(int a, int *b) {
    if (a <= 1)
        return a;
    
    if (b[a] != -1)  // Return if already computed
        return b[a];

    int x, y;

    #pragma omp task shared(b) firstprivate(a)
    x = fib(a - 1, b);

    #pragma omp task shared(b) firstprivate(a)
    y = fib(a - 2, b);

    #pragma omp taskwait  // Ensure x and y are computed before storing the result
    b[a] = x + y;
    return b[a];
}

int main() {
    int a;
    
    // Taking user input
    printf("Enter the number of Fibonacci terms to print: ");
    scanf("%d", &a);
    
    if (a < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    int *b = (int *)malloc((a + 1) * sizeof(int));

    // Initialize memoization array with -1
    for (int c = 0; c <= a; c++)
        b[c] = -1;

    #pragma omp parallel
    {
        #pragma omp single  // Ensures only one thread starts the computation
        {
            for (int c = 0; c < a; c++) {
                fib(c, b);
            }
        }
    }

    // Print Fibonacci series
    printf("Fibonacci Series up to %d terms:\n", a);
    for (int c = 0; c < a; c++) {
        printf("%d ", b[c]);
    }
    printf("\n");

    free(b); // Free allocated memory
    return 0;
}
