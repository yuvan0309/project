#include<stdio.h>

void prims(int n, int s, int cost[][10]) {
    int i, j, a, b, min, total_cost = 0, edge_count = 0;
    int tree_vertex[10] = { 0 };
    tree_vertex[s] = 1;

    while (edge_count < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (tree_vertex[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (tree_vertex[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("Edge from vertices %d to %d in %d\n", a, b, min);
        tree_vertex[b] = 1;
        total_cost += min;
        edge_count++;
    }
    printf("Min cost= %d\n", total_cost);
}

void main() {
    int n, s, cost[10][10];
    printf("Enter the no.of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    prims(n, s, cost);
}
// Output:
// Enter the no.of vertices: 5
// Enter the cost matrix:
// 0 10 999 999 999
// 999 0 999 999 5
// 999 999 0 3 999
// 999 999 999 0 1
// 999 999 999 999 0
// Enter the source vertex: 0
// Edge from vertices 0 to 1 in 10
// Edge from vertices 1 to 4 in 5
// Edge from vertices 1 to 3 in 3
// Edge from vertices 3 to 2 in 1
// Min cost= 19
