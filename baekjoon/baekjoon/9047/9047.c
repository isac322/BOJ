#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(char*)a - *(char*)b;
}

int cmp2(const void *a, const void *b) {
	return *(char*)b - *(char*)a;
}

int main() {
	int n, min, max, cnt;
	char in[5];

	scanf("%d\n", &n);
	while (n--) {
		min = max = 0;
		gets(in);
		for (cnt = 0; atoi(in) != 6174; cnt++) {
			qsort(in, 4, sizeof(char), cmp);
			min = atoi(in);

			qsort(in, 4, sizeof(char), cmp2);
			max = atoi(in);
			sprintf(in, "%04d", max - min);
		}
		printf("%d\n", cnt);
	}

}