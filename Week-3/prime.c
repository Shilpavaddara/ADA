#include <stdio.h>
#define MAX 100

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, ne = 1;
    int min, mincost = 0;
    int a = 0, b = 0, u = 0, v = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    while (ne < n) {
        min = 9999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (unionSet(u, v)) {
            printf("Edge %d: (%d -> %d) cost = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
