#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
MPI_Init(&argc, &argv);
int rank, size, send_data, recv_data;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int left = (rank - 1 + size) % size; // Left neighbor
int right = (rank + 1) % size; // Right neighbor
send_data = rank; // Send own rank as data
MPI_Sendrecv(&send_data, 1, MPI_INT, right, 0,
&recv_data, 1, MPI_INT, left, 0,
MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("Process %d received data %d from process %d\n", rank, recv_data, left);
MPI_Finalize();
return 0;
}
