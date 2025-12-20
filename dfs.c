#include <stdio.h>

#define MAX 10

void dfs(int adj[MAX][MAX], int visited[MAX], int current, int n) {
    // Düğümü ziyaret et
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        // Komşuysa ve ziyaret edilmemişse derine git
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(adj, visited, i, n);
        }
    }
}

int main() {
    int n = 5;
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int visited[MAX] = {0};

    printf("DFS Gezginligi: ");
    dfs(adj, visited, 0, n);
    return 0;
}