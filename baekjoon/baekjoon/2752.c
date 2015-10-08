#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main(){
	int num[3] = { 0 };
	int i = 0;

	for (; i < 3; i++) scanf("%d", num + i);
	qsort(num, 3, sizeof(int), cmp);
	
	for (i = 0; i < 3; i++)
		printf("%d ", num[i]);
}