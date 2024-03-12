#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjacencyList;
    int** adjacencyMatrix;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    int i, j;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjacencyList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (i = 0; i < V; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    graph->adjacencyMatrix = (int**)malloc(V * sizeof(int*));
    for (i = 0; i < V; ++i) {
        graph->adjacencyMatrix[i] = (int*)malloc(V * sizeof(int));
        for (j = 0; j < V; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    graph->adjacencyMatrix[src][dest] = 1;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* current = graph->adjacencyList[src];
    struct Node* prev = NULL;

    while (current != NULL && current->vertex != dest) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            graph->adjacencyList[src] = current->next;
        }
        free(current);
    }

    graph->adjacencyMatrix[src][dest] = 0;
}

void displayAdjacencyList(struct Graph* graph) {
    int i;
    printf("Adjacency List:\n");
    for (i = 0; i < graph->V; ++i) {
        printf("%d: ", i);
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void displayAdjacencyMatrix(struct Graph* graph) {
    int i,j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < graph->V; ++i) {
        for (j = 0; j < graph->V; ++j) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, choice, i;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Display Adjacency List\n");
        printf("4. Display Adjacency Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices for the new edge: ");
                int src, dest;
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;

            case 2:
                printf("Enter source and destination vertices to delete the edge: ");
                scanf("%d %d", &src, &dest);
                deleteEdge(graph, src, dest);
                break;

            case 3:
                displayAdjacencyList(graph);
                break;

            case 4:
                displayAdjacencyMatrix(graph);
                break;

            case 5:
                for (i = 0; i < graph->V; ++i) {
                    struct Node* current = graph->adjacencyList[i];
                    while (current != NULL) {
                        struct Node* temp = current;
                        current = current->next;
                        free(temp);
                    }
                    free(graph->adjacencyMatrix[i]);
                }
                free(graph->adjacencyList);
                free(graph->adjacencyMatrix);
                free(graph);
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

