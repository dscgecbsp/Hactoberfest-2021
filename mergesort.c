#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
void merge(int arr[], int l, int m, int r, int *L, int *R) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r, int *L, int *R) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, L, R);
        mergeSort(arr, m + 1, r, L, R);

        merge(arr, l, m, r, L, R);
    }
}

// Function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    // Allocate memory for temporary arrays
    int *L = (int *)malloc(arr_size / 2 * sizeof(int));
    int *R = (int *)malloc((arr_size - arr_size / 2) * sizeof(int));

    mergeSort(arr, 0, arr_size - 1, L, R);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    // Free allocated memory
    free(L);
    free(R);

    return 0;
}
