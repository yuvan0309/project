#include<stdio.h>

int x[10], w[10], count = 0, n;

void findSubsetsWithSum(int cs, int ci, int rs) {
    x[ci] = 1;
    if (cs + w[ci] == n) {
        printf("\nSubset %d:\n", ++count);
        for (int i = 1; i <= ci; i++) {
            if (x[i] == 1)
                printf("%d\t", w[i]);
        }
    } else if (cs + w[ci] + w[ci + 1] <= n) {
        findSubsetsWithSum(cs + w[ci], ci + 1, rs - w[ci]);
    }
    if ((cs + rs - w[ci] >= n) && (cs + w[ci + 1] <= n)) {
        x[ci] = 0;
        findSubsetsWithSum(cs, ci + 1, rs - w[ci]);
    }
}

int main() {
    int sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    if (sum < n) {
        printf("No solution exists\n");
        return 0;
    }
    printf("Enter the sum: ");
    scanf("%d", &n);
    findSubsetsWithSum(0, 1, sum);
    if (count == 0)
        printf("No solution exists\n");
    return 0;
}