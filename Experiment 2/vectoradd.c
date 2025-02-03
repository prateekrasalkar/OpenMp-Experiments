#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void sequential(){
long long num_terms = 100000000;
       	 double *arr = (double *)malloc(num_terms * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
         }
        double start,end;
        start = omp_get_wtime();
        for(int i=0;i<num_terms;i++){
                arr[i] = arr[i] + 10.098;
        }
        end = omp_get_wtime();
        printf("Sequential Addition : %f\n\n",end-start);
}

int main(){
	sequential();
	long long num_terms = 100000000;
	double *arr = (double *)malloc(num_terms * sizeof(double));  
    if (arr == NULL) {
        printf("Memory allocation failed\n");
         }

	double start,end;
	start = omp_get_wtime();
	#pragma omp parallel for
	for(int i =0;i<num_terms;i++){
	arr[i] = arr[i] + 10.098;
	}
	end = omp_get_wtime();
	printf("Parallel Addition : %f\n\n",end-start);

	return 0;
	


}
