#include <stdio.h>
#include <limits.h>

int cost[10][10], n;

void prim(int n, int cost[10][10]){
    int vt[10] = {0};
    int a = 0, b = 0, min, mincost = 0, ne = 0;
    vt[0] = 1;
    while (ne < n - 1){
        min = INT_MAX;
        for (int i = 0; i < n; i++){
            if (vt[i] == 1)
                for (int j = 0; j < n; j++)
                    if (cost[i][j] < min && vt[j] == 0){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
        }
        printf("Edge from vertex %d to vertex %d and the cost %d\n", a, b, min);
        vt[b] = 1;
        ne++;
        mincost += min;
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("minimum spanning tree cost is %d", mincost);
}

int main(){
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    prim(n, cost);
    return 0;
}
//Enter the no. of vertices: 5
//Enter the cost matrix
//0 1 1 0 0
//0 0 0 1 1
//0 0 0 0 0
//0 0 0 1 0
//0 0 0 0 1
//Edge from vertex 0 to vertex 1 and the cost 1
//Edge from vertex 0 to vertex 2 and the cost 1
//Edge from vertex 1 to vertex 3 and the cost 1
//Edge from vertex 1 to vertex 4 and the cost 1
//minimum spanning tree cost is 4
