#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right, int* opcount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];
    int i,j;
    for (i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int k = left;

    while (i < n1 && j < n2) {
        (*opcount)++;
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right, int* opcount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, opcount);
        mergeSort(arr, mid + 1, right, opcount);
        merge(arr, left, mid, right, opcount);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Hard-coded input
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i,n;
    printf("Given array is:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int opcount = 0; // Initialize opcount

    // Measure execution time
    clock_t start_time = clock();
    mergeSort(arr, 0, arr_size - 1, &opcount);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorted array is:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Input size: %d\n", arr_size);
    printf("Opcount: %d\n", opcount);
    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}


