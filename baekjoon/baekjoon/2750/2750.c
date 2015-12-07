#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(short*)a - *(short*)b;
}

int main() {
	int N;
	int i;
	short M[1000] = { 0 };

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", M + i);
	qsort(M, N, sizeof(short), cmp);
	for (i = 0; i < N; i++)
		printf("%d\n", M[i]);
}