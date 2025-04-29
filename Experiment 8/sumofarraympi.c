#include <stdio.h>
#include <mpi.h>
#define N 10 // Total array size
int main(int argc, char** argv) {
MPI_Init(&argc, &argv);
int rank, size;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
if (size != 2) {
printf("Run the program with exactly 2 processes.\n");
MPI_Finalize();
return 0;
}
int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sample array
int local_sum = 0, total_sum;
int start = rank * (N / 2);
int end = start + (N / 2);
for (int i = start; i < end; i++) {
local_sum += A[i];
}
MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
if (rank == 0) {
printf("Total sum of the array: %d\n", total_sum);
}
MPI_Finalize();
return 0;
}
