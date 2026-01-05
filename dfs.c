#include <stdio.h>
#include <stdlib.h>

void DFS(int matrix[10][10], int visited[], int n, int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (matrix[start][i] == 1 && !visited[i]) {
            DFS(matrix, visited, n, i);
        }
    }
}

int main() {
    int n = 5;
    int visited[5] = {0, 0, 0, 0, 0};
    int matrix[10][10] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    printf("DFS Gezintisi: ");
    DFS(matrix, visited, n, 0);

    return 0;
}