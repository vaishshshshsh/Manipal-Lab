#include <stdio.h>
#define MAX_N 10 // Maximum number of jobs/people (adjustable)

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int n, int *min_cost, int *assignment, int cost_matrix[][MAX_N], long long *opcount) {
    (*opcount)++; 

    if (n == 1) {
        int total_cost = 0;
        for (int i = 0; i < n; i++) {
            total_cost += cost_matrix[i][assignment[i]];
        }
        if (total_cost < *min_cost) {
            *min_cost = total_cost;
            for (int i = 0; i < n; i++) {
                assignment[i] = arr[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        (*opcount)++; 
        swap(&arr[0], &arr[i]);
        permute(arr + 1, n - 1, min_cost, assignment, cost_matrix, opcount);
        swap(&arr[0], &arr[i]); // Backtrack
    }
}

void assignmentProblem(int cost_matrix[][MAX_N], int n, long long *opcount) {
    int min_cost = INT_MAX; // Initialize with maximum integer value
    int assignment[MAX_N];

    int arr[MAX_N]; // Array to store permutations
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    permute(arr, n, &min_cost, assignment, cost_matrix, opcount);

    printf("Minimum cost: %d\n", min_cost);
    printf("Optimal assignment: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", assignment[i] + 1); // Print 1-based indexing
    }
    printf("\n");
    printf("Operation count: %lld\n", *opcount);
}

int main() {
    int n;
    printf("Enter the number of jobs/people (maximum %d): ", MAX_N);
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("Error: Maximum size exceeded. Please reduce n.\n");
        return 1;
    }

    int cost_matrix[MAX_N][MAX_N];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }

    long long opcount = 0; // Initialize opcount
    assignmentProblem(cost_matrix, n, &opcount);

    return 0;
}
