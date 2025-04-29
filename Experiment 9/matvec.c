#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4  // Change this size for larger matrices

int main(int argc, char* argv[]) {
    int rank, size;
    int matrix[N][N], vector[N], local_matrix[N], local_result;
    int result[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_proc = N / size;

    if (rank == 0) {
        // Initialize matrix and vector
        for (int i = 0; i < N; i++) {
            vector[i] = 1;
            for (int j = 0; j < N; j++) {
                matrix[i][j] = i + j;
            }
        }
    }

    // Broadcast the vector to all processes
    MPI_Bcast(vector, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Scatter the rows of the matrix
    MPI_Scatter(matrix, N * rows_per_proc, MPI_INT, local_matrix, N * rows_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    int local_results[rows_per_proc];

    for (int i = 0; i < rows_per_proc; i++) {
        local_results[i] = 0;
        for (int j = 0; j < N; j++) {
            local_results[i] += local_matrix[i * N + j] * vector[j];
        }
    }

    // Gather the results to the root
    MPI_Gather(local_results, rows_per_proc, MPI_INT, result, rows_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Result Vector:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
