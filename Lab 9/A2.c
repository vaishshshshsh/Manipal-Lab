#include <stdio.h>

// Function to perform counting sort
void countingSort(int array[], int size) {
    // Find the largest element in the array
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize a count array with all zeros
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the count of each element at their respective index in the count array
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Calculate the cumulative sum in the count array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in the output array based on their cumulative count
    int output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int main() {
    int data[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    countingSort(data, size);

    printf("\nSorted Array in Ascending Order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
