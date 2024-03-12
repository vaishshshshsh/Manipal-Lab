#include <stdio.h>
#include <time.h>
#include <limits.h>
#define MAX_N 10 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculateDistance(int graph[][MAX_N], int i, int j) {
    return graph[i][j];
}

int isVisited(int visited[], int n, int city) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == city) {
            return 1;
        }
    }
    return 0;
}

int findMinCostTour(int graph[][MAX_N], int n, int currPos, int visited[], int cost, long long *opcount) {
    (*opcount)++; 
    if (currPos == n) {
        return cost + graph[currPos][0]; 
    }

    int minCost = INT_MAX;

    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (isVisited(visited, n, nextCity) == 0) {
            visited[currPos] = nextCity; 
            int newCost = cost + calculateDistance(graph, currPos, nextCity);
            int tempCost = findMinCostTour(graph, n, nextCity, visited, newCost, opcount);
            minCost = (tempCost < minCost) ? tempCost : minCost;
            visited[currPos] = -1; 
        }
    }

    return minCost;
}

int main() {
    int n;
    printf("Enter the number of cities (maximum %d): ", MAX_N);
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("Error: Maximum size exceeded. Please reduce n.\n");
        return 1;
    }

    int graph[MAX_N][MAX_N];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[MAX_N]; 
    for (int i = 0; i < n; i++) {
        visited[i] = -1; 
    }

    long long opcount = 0; 
    clock_t start_time = clock(); 

    int minCost = findMinCostTour(graph, n, 0, visited, 0, &opcount);

    clock_t end_time = clock(); 
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Minimum cost tour: %d\n", minCost);
    printf("Operation count: %lld\n", opcount);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
