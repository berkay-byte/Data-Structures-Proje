#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int queue[MAX], rear = -1, front = -1;

    // Başlangıç düğümünü ziyaret et ve kuyruğa ekle
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            // Eğer komşuysa ve ziyaret edilmemişse
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n = 5; // Düğüm sayısı
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int visited[MAX] = {0};

    printf("BFS Gezginligi: ");
    bfs(adj, visited, 0, n);
    return 0;
}