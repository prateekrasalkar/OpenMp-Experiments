#include <stdio.h>
#include <omp.h>

int main() {
    int arr1[] = {1, 2, 9, 10, 15, 16};
    int arr2[] = {15, 16, 19, 31, 35, 46};
    int arr3[12]; // Resultant merged array
    int n = 6;
    int i = 0, j = 0, k = 0;

    // Merge two sorted arrays using two pointers
    #pragma omp parallel while
    while (i < n && j < n) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1, if any
    #pragma omp parallel while
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2, if any
    #pragma omp parallel while
    while (j < n) {
        arr3[k++] = arr2[j++];
    }


    printf("Merged Sorted Array:\n");
    #pragma omp parallel for
    for (int m = 0; m < 12; m++) {
        printf("%d ", arr3[m]);
    }
    printf("\n");

    return 0;
}
