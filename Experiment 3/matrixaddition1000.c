#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void size250threads2(){
	int size=1000;
	int num_threads;
	//int **mat1 = (int **)malloc(size * sizeof(int *));
	double **mat1 = (double **)malloc(size*sizeof(double *));
	double **mat2 = (double **)malloc(size*sizeof(double *));
	double **additionmat = (double **)malloc(size*sizeof(double *));
	double start = omp_get_wtime();
	#pragma omp parallel for num_threads(2)
	 for (int i = 0; i < size; i++) {
        mat1[i] = (double *)malloc(size * sizeof(double));
        mat2[i] = (double *)malloc(size * sizeof(double));
        additionmat[i] = (double *)malloc(size * sizeof(double));
    }
	#pragma omp parallel for num_threads(2)
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			mat1[i][j] = rand()%10;
			mat2[i][j] = rand()%10;
		
		}
	}
	#pragma omp parallel for num_threads(2)
	for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
			additionmat[i][j] = mat1[i][j]+mat2[i][j];

                }
        }
	#pragma omp parallel num_threads(2)
	{
	
		#pragma omp single
		num_threads = omp_get_num_threads();
		
	}
	double end = omp_get_wtime();
	printf("\n Execution Time %f for size = %d and threads = %d\n",end-start,size,num_threads);

	for (int i = 0; i < size; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(additionmat[i]);
    }
    free(mat1);
    free(mat2);
    free(additionmat);

}

void size250threads4(){
        int size=1000;
        int num_threads;
        //int **mat1 = (int **)malloc(size * sizeof(int *));
        double **mat1 = (double **)malloc(size*sizeof(double *));
        double **mat2 = (double **)malloc(size*sizeof(double *));
        double **additionmat = (double **)malloc(size*sizeof(double *));
        double start = omp_get_wtime();
        #pragma omp parallel for num_threads(4)
         for (int i = 0; i < size; i++) {
        mat1[i] = (double *)malloc(size * sizeof(double));
        mat2[i] = (double *)malloc(size * sizeof(double));
        additionmat[i] = (double *)malloc(size * sizeof(double));
    }
        #pragma omp parallel for num_threads(4)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        mat1[i][j] = rand()%10;
                        mat2[i][j] = rand()%10;

                }
        }
        #pragma omp parallel for num_threads(4)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        additionmat[i][j] = mat1[i][j]+mat2[i][j];

                }
        }
        #pragma omp parallel num_threads(4)
        {

                #pragma omp single
                num_threads = omp_get_num_threads();

        }
        double end = omp_get_wtime();
        printf("\n Execution Time %f for size = %d and threads = %d\n",end-start,size,num_threads);

	for (int i = 0; i < size; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(additionmat[i]);
    }
    free(mat1);
    free(mat2);
    free(additionmat);

}
void size250threads6(){
        int size=1000;
        int num_threads;
        //int **mat1 = (int **)malloc(size * sizeof(int *));
        double **mat1 = (double **)malloc(size*sizeof(double *));
        double **mat2 = (double **)malloc(size*sizeof(double *));
        double **additionmat = (double **)malloc(size*sizeof(double *));
        double start = omp_get_wtime();
        #pragma omp parallel for num_threads(6)
         for (int i = 0; i < size; i++) {
        mat1[i] = (double *)malloc(size * sizeof(double));
        mat2[i] = (double *)malloc(size * sizeof(double));
        additionmat[i] = (double *)malloc(size * sizeof(double));
    }
        #pragma omp parallel for num_threads(6)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        mat1[i][j] = rand()%10;
                        mat2[i][j] = rand()%10;

                }
        }
        #pragma omp parallel for num_threads(6)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        additionmat[i][j] = mat1[i][j]+mat2[i][j];

                }
        }
        #pragma omp parallel num_threads(6)
        {

                #pragma omp single
                num_threads = omp_get_num_threads();

        }
        double end = omp_get_wtime();
        printf("\n Execution Time %f for size = %d and threads = %d\n",end-start,size,num_threads);

        for (int i = 0; i < size; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(additionmat[i]);
    }
    free(mat1);
    free(mat2);
    free(additionmat);

}

void size250threads8(){
        int size=1000;
        int num_threads;
        //int **mat1 = (int **)malloc(size * sizeof(int *));
        double **mat1 = (double **)malloc(size*sizeof(double *));
        double **mat2 = (double **)malloc(size*sizeof(double *));
        double **additionmat = (double **)malloc(size*sizeof(double *));
        double start = omp_get_wtime();
        #pragma omp parallel for num_threads(8)
         for (int i = 0; i < size; i++) {
        mat1[i] = (double *)malloc(size * sizeof(double));
        mat2[i] = (double *)malloc(size * sizeof(double));
        additionmat[i] = (double *)malloc(size * sizeof(double));
    }
        #pragma omp parallel for num_threads(8)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        mat1[i][j] = rand()%10;
                        mat2[i][j] = rand()%10;

                }
        }
        #pragma omp parallel for num_threads(8)
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        additionmat[i][j] = mat1[i][j]+mat2[i][j];

                }
        }
        #pragma omp parallel num_threads(8)
        {

                #pragma omp single
                num_threads = omp_get_num_threads();

        }
        double end = omp_get_wtime();
        printf("\n Execution Time %f for size = %d and threads = %d\n",end-start,size,num_threads);

        for (int i = 0; i < size; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(additionmat[i]);
    }
    free(mat1);
    free(mat2);
    free(additionmat);

}

int main(){
size250threads2();
size250threads4();
size250threads6();
size250threads8();
return 0;
}
