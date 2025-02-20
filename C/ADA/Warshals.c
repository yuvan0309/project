#include<stdio.h>

void warshal(int a[10][10],int n){
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
            }
        }
    }
}

void main(){
    int n,adj[10][10];
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    warshal(adj,n);
    printf("Transitive closure\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
// Output:
// Enter number of vertices
// 4
// Enter adjacency matrix
// 0 1 0 0
// 0 0 0 1
// 0 0 0 0
// 1 0 1 0
// Transitive closure
// 1 1 1 1
// 1 1 1 1
// 0 0 0 0
// 1 1 1 1
// Time Complexity: O(n^3)