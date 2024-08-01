#include<stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))

int cost[10][10],n,dist[10];


void dijkstra(int source){
    int s[10]={0};
    int min,w=0;
    for(int i=0;i<n;i++){
        dist[i]=cost[source][i];
    }
    dist[source]=0;
    s[source]=1;
    for(int i=0;i<n-1;i++){
        min=999;
        for(int j=0;j<n;j++){
            if(s[j]==0 && dist[j]<min){
                min=dist[j];
                w=j;
            }
        }
        s[w]=1;
        for(int v=0;v<n;v++){
            if(s[v]==0 && cost[w][v]!=999){
                dist[v]=min(dist[v],dist[w]+cost[w][v]);
            }
        }
    }
}

int main(){
    int source;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter source vertex\n");
    scanf("%d",&source);
    dijkstra(source);
    printf("Shortest path from source vertex %d\n",source);
    for(int i=0;i<n;i++){
        printf("%d to %d = %d\n",source,i,dist[i]);
    }
    return 0;
}
// Output:
// Enter number of vertices
// 5
// Enter cost matrix
// 0 10 999 999 999
// 999 0 999 999 5
// 999 999 0 3 999
// 999 999 999 0 1
// 999 999 999 999 0
// Enter source vertex
// 0
// Shortest path from source vertex 0
// 0 to 0 = 0
// 0 to 1 = 10
// 0 to 2 = 13
// 0 to 3 = 16
// 0 to 4 = 6
