#include<stdio.h>

int min(int a,int b){
    return a<b?a:b;
}

void floyd(int d[][10],int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int n,cost[10][10];
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    floyd(cost,n);
    printf("Shortest path matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}
// Output:
// Enter number of vertices
// 4
// Enter cost matrix
// 0 1 999 999
// 999 0 1 999
// 999 999 0 1
// 1 999 999 0
// Shortest path matrix
// 0 1 2 3
// 999 0 1 2
// 999 999 0 1
// 1 2 3 0
// Time Complexity: O(n^3)
