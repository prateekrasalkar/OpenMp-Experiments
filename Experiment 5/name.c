#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        char *names[] = {"Harshal", "Pratik", "Prateek", "Sagar", "Aman", "Rajwardhan", "Rajat", "Sahil"};
        
        // Check if the thread_id corresponds to "Prateek" (index 2)
        if (thread_id % 8 == 2) {
            printf("Thread %d: %s\n", thread_id, names[2]);
        }
    }

    return 0;
}
