#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, arr[50] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    qsort(arr, n, sizeof(int), cmp);
    printf("%d", arr[0] * arr[n - 1]);
}