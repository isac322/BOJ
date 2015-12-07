#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int caseN;
	int num;
	int re[1000] = { 0 };
	int res[1000] = { 0 };
	int *tmp;
	int i,j,k;

	scanf("%d", &caseN);
	for (i = 0; i < caseN; i++) {
		k = 0;
		memset(re, 0, 1000);
		memset(res, 0, 1000);
		scanf("%d", &num);

		for (j = 2; j <= num; j++) {
			if (!(num % j)) {
				if ((tmp = (int *)bsearch(&j, re, k, sizeof(int), cmp))) {
					res[tmp - re]++;
				} else {
					re[k] = j;
					res[k++] = 1;
				}
				num /= j;
				j = 1;
			}
		}

		for (j = 0; res[j]; j++) printf("%d %d\n", re[j], res[j]);
	}
}