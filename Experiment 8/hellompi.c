mpicc hello.c -o hello
mpirun -np 4 ./hello

#include<stdio.h>
#include<mpi.h>
void main(int argc ,char** argv)
{
MPI_Init(&argc,&argv);
int size;
MPI_Comm_size(MPI_COMM_WORLD,&size);
printf("HEllO \n");
MPI_Finalize();
}
