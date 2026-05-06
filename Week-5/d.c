#include <stdio.h>
#define INF 9999

int min(int d[], int v[], int n) {
    int m = INF, pos = -1;
    for (int i = 0; i < n; i++)
        if (!v[i] && d[i] < m) {
            m = d[i];
            pos = i;
        }
    return pos;
}

int main() {
    int n, g[10][10], d[10], v[10], src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0; i < n; i++) {
        d[i] = INF;
        v[i] = 0;
    }

    d[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = min(d, v, n);
        if (u == -1) break;
        v[u] = 1;

        for (int j = 0; j < n; j++)
            if (!v[j] && g[u][j] && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }

    printf("Vertex Distance\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, d[i]);

    return 0;
}
