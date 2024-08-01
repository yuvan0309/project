#include<stdio.h>
#include<math.h>

int place(int x[],int k){
    for(int i=0;i<k;i++){
        if((x[i]==x[k])||((abs(x[i]-x[k]))==abs(i-k))){
            return 0;
        }
    }
    return 1;
}

int nqueens(int n){
    int x[10],k,count=0;
    k=1;
    x[k]=0;
    while(k!=0){
        x[k]++;
        while(x[k]<=n && !place(x,k)){
            x[k]++;
        }
        if(x[k]<=n){
            if(k==n){
                printf("Solution %d\n",++count);
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++)
                        printf("%c",(j==x[i])?'Q':'X');
                printf("\n");
                }
            }else{
                ++k;
                x[k]=0;
            }
        }else{
            k--;
        }
    }
    return count;
}

void main(){
    int n;
    printf("Enter the size of chessboard:\n");
    scanf("%d",&n);
    printf("\n The no.of possibilites are %d",nqueens(n));
}
// // Output:
// // Enter the size of chessboard:
// // 4
// // Solution 1
// // XQXX
// // XXQX
// // QXXX
// // XXXQ
// // Solution 2
// // XXQX
// // QXXX
// // XXXQ
// // XQXX
// // The no.of possibilites are 2
