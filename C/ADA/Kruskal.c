#include <stdio.h>
#include <limits.h>

void kruskal(int n, int cost[10][10]){
    int par[n];
    int a = 0, b = 0, u = 0, v = 0, min, mincost = 0, ne = 0;
    for (int i = 0; i < n; i++)
        par[i] = -1;

    printf("the minimum spanning tree edges are...\n");
    while (ne < n - 1){
        min = INT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        while (par[u] != -1)
            u = par[u];
        while (par[v] != -1)
            v = par[v];

        if (u != v){
            printf("From vertex %d to vertex %d and the cost = %d\n", a, b, min);
            mincost += min;
            par[v] = u;
            ne++;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("Cost of MST = %d\n", mincost);
}

int main(){
    int n;
    printf("Enter the no. of vertices:");
    scanf("%d", &n);
    int cost[10][10];
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    kruskal(n, cost);
    return 0;
}
//Enter the no. of vertices: 5
//Enter the cost matrix
//0 1 1 0 0
//0 0 0 1 1
//0 0 0 0 0
//0 0 0 1 0
//0 0 0 0 1
//From vertex 0 to vertex 1 and the cost = 1
//From vertex 0 to vertex 2 and the cost = 1
//From vertex 1 to vertex 3 and the cost = 1
//From vertex 1 to vertex 4 and the cost = 1
//Cost of MST = 4
