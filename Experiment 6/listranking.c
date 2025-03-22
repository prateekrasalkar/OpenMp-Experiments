#include <stdio.h>
#include<omp.h>

int main() {

    int arr[] = {5, 2, 9, 1, 5, 6};
    int n=6;
     int i, j, temp;
    #pragma omp parallel for
    for (i = n ;i > 0;i--) {
    #pragma omp parallel for
        for (j = i-1; j > 0; j--) {
            if (arr[i] < arr[j ]) {
                
                temp = arr[i];
                arr[i] = arr[j];
                arr[j ] = temp;
            }
        }
    }
    int p=1;
     for (int i = n-1; i >=0; i--) {
        printf("Element = %d Rank = %d \n", arr[i],p);
        p++;
    }
    printf("\n");
  

    return 0;
}
