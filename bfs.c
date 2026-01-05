#include <stdio.h>
#include <stdlib.h>

void BFS(int matrix[10][10], int n, int start) {
    int visited[10] = {0};
    int queue[10];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Gezintisi: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5;
    int matrix[10][10] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    BFS(matrix, n, 0);

    return 0;
}