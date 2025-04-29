#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4  // Change this size as needed

int main(int argc, char* argv[]) {
    int rank, size;
    int A[N][N], B[N][N], C[N][N];
    int local_A[N][N], local_C[N][N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_proc = N / size;

    if (rank == 0) {
        // Initialize matrices A and B
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + j;
                B[i][j] = i * j;
            }
        }
    }

    // Broadcast matrix B to all processes
    MPI_Bcast(B, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter rows of matrix A
    MPI_Scatter(A, N * rows_per_proc, MPI_INT, local_A, N * rows_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < rows_per_proc; i++) {
        for (int j = 0; j < N; j++) {
            local_C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                local_C[i][j] += local_A[i][k] * B[k][j];
            }
        }
    }

    // Gather the resulting rows back to C
    MPI_Gather(local_C, N * rows_per_proc, MPI_INT, C, N * rows_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result Matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%4d ", C[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
