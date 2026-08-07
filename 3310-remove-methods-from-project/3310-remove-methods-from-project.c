#include <stdlib.h>
#include <stdbool.h>

int* remainingMethods(int n, int k, int** invocations,
                      int invocationsSize, int* invocationsColSize,
                      int* returnSize) {

    // Build adjacency list
    int *degree = calloc(n, sizeof(int));

    for (int i = 0; i < invocationsSize; i++) {
        degree[invocations[i][0]]++;
    }

    int **graph = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        graph[i] = malloc(degree[i] * sizeof(int));
        degree[i] = 0;
    }

    for (int i = 0; i < invocationsSize; i++) {
        int a = invocations[i][0];
        int b = invocations[i][1];

        graph[a][degree[a]++] = b;
    }

    // Find suspicious methods
    bool *suspicious = calloc(n, sizeof(bool));

    int *queue = malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = k;
    suspicious[k] = true;

    while (front < rear) {

        int u = queue[front++];

        for (int i = 0; i < degree[u]; i++) {

            int v = graph[u][i];

            if (!suspicious[v]) {
                suspicious[v] = true;
                queue[rear++] = v;
            }
        }
    }

    // Check if any non-suspicious method calls
    // a suspicious method
    for (int i = 0; i < invocationsSize; i++) {

        int a = invocations[i][0];
        int b = invocations[i][1];

        if (!suspicious[a] && suspicious[b]) {

            // Cannot remove suspicious methods
            int *ans = malloc(n * sizeof(int));

            for (int j = 0; j < n; j++)
                ans[j] = j;

            *returnSize = n;

            for (int j = 0; j < n; j++)
                free(graph[j]);

            free(graph);
            free(degree);
            free(suspicious);
            free(queue);

            return ans;
        }
    }

    // Remove suspicious methods
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i])
            count++;
    }

    int *ans = malloc(count * sizeof(int));

    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i]) {
            ans[idx++] = i;
        }
    }

    *returnSize = count;

    // Free memory
    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(degree);
    free(suspicious);
    free(queue);

    return ans;
}