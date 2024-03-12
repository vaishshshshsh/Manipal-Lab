#include <stdio.h>
#include <stdlib.h> // For clock_t, clock(), and CLOCKS_PER_SEC
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high, int* opcount) {
    int pivot = arr[high]; // Choose the pivot (last element)
    int i = low - 1; // Index of smaller element
    int j;

    for (j = low; j <= high - 1; j++) {
        (*opcount)++; // Increment opcount for each comparison
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high, int* opcount) {
    if (low < high) {
        int pi = partition(arr, low, high, opcount);
        quickSort(arr, low, pi - 1, opcount);
        quickSort(arr, pi + 1, high, opcount);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int i;
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int opcount = 0; // Initialize opcount

    // Measure execution time
    clock_t start_time = clock();
    quickSort(arr, 0, n - 1, &opcount);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Input size: %d\n", n);
    printf("Opcount: %d\n", opcount);
    printf("Time taken: %.6f seconds\n", time_taken);

    return 0;
}
