#include <stdio.h>

void dfs(int v, int n, int matrix[10][10], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (matrix[v][i] == 1 && !visited[i]) {
            dfs(i, n, matrix, visited);
        }
    }
}

void findClusters(int n, int matrix[10][10]) {
    int visited[10] = {0};
    int clusterCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            dfs(i, n, matrix, visited);
            printf("\n");
        }
    }
}

int main() {
    int n = 6;
    int matrix[10][10] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    findClusters(n, matrix);

    return 0;
}