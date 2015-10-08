#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main(){
	int a[10] = { 0 };
	int max, i;

	scanf("%d", &max);
	while (max--) {
		for (i = 0; i < 10; i++)
			scanf("%d", a + i);
		qsort(a, 10, sizeof(int), cmp);
		printf("%d\n", a[7]);
	}
}