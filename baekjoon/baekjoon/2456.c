#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	int *A = (int *)b, *B = (int *)a;
	int N;

	if (A[4] == B[4]) {
		if (A[3] == B[3]) {
			*B = *A = 0;
			N = 2;
		} else N = 3;
	} else N = 4;
	return A[N] - B[N];
}

int main() {
	int N, A[3][5] = {{1,0},{2,0},{3,0}};
	int i = 0, j, T;

	scanf("%d", &N);
	for (; i < N; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &T);
			A[j][T]++;
			A[j][4] += T;
		}
	}

	qsort(A, 3, sizeof(int) * 5, cmp);
	printf("%d %d\n", **A, *(*A +4));
}