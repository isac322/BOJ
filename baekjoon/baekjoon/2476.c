#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main(){
	int mat[1000] = { 0 }, in[3] = { 0 };
	int max;
	int i, j;

	scanf("%d", &max);
	for (i = 0; i < max; i++) {
		for (j = 0; j < 3; j++)
			scanf("%d", in + j);
		if (in[0] == in[1] && in[1] == in[2])
			mat[i] = 10000 + in[2] * 1000;
		else if (in[0] != in[1] && in[1] != in[2] && in[0] != in[2]) {
			qsort(in, 3, sizeof(int), cmp);
			mat[i] = in[2] * 100;
		} else
			mat[i] = 1000 + 100 * (in[0] == in[1] ? in[0] : in[1]);
	}
	qsort(mat, max, sizeof(int), cmp);
	printf("%d", mat[max - 1]);
}