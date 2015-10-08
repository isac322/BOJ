#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int a[3], dif1, dif2;
	int i;
	for(i = 0; i < 3; i++)
		scanf("%d", a + i);
	qsort(a, 3, sizeof(int), cmp);
	dif1 = a[1] - a[0];
	dif2 = a[2] - a[1];
	if(dif1 == dif2) printf("%d", dif1 + a[2]);
	else if(dif1 > dif2) printf("%d", a[0] + dif2);
	else if(dif1 < dif2) printf("%d", a[1] + dif1);
}