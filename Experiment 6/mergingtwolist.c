#include <stdio.h>
#include <omp.h>

void merge(int* A, int N, int* B, int M, int* C) {
    #pragma omp parallel for
    for (int i = 0; i < N + M; i++) {
        int a_idx = 0, b_idx = 0;
        
        #pragma omp critical
        {
            if (a_idx < N && (b_idx >= M || A[a_idx] < B[b_idx]))
                C[i] = A[a_idx++];
            else
                C[i] = B[b_idx++];
        }
    }
}

int main() {
    int A[] = {1, 3, 5, 7}, B[] = {2, 4, 6, 8}, C[8];

    merge(A, 4, B, 4, C);

    for (int i = 0; i < 8; i++) printf("%d ", C[i]);
    return 0;
}
