#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int arr[1000000];
int main(n, i) {
	for(scanf("%d", &n),i=0;i<n;i++)scanf("%d",arr+i);
    qsort(arr,n,sizeof(int),cmp);
    for(i=0;i<n;i++) printf("%d\n", arr[i]);
}