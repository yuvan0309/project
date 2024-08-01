#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        } else {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < p) {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < q) {
        a[k] = c[j];
        j++;
        k++;
    }
}

void Mergesort(int a[], int n) {
    if (n < 2) {
        return;
    }
    int p = n / 2;
    int q = n - p;
    int b[p], c[q];
    for (int i = 0; i < p; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < q; i++) {
        c[i] = a[i + p];
    }
    Mergesort(b, p);
    Mergesort(c, q);
    merge(b, p, c, q, a);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    Mergesort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}