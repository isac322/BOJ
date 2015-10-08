#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) { return *(int *) a - *(int *) b; }

int main() {
	int o[10000] = { 0 };
	int tmp[1230] = { 0 };
	int i, j, l = 0, temp;
	int a, b, mi;
	int test, num;
	int *p;

	for (i = 0; i < 10000; i++) o[i] = i + 1;
	for (i = 2; i < 10000; i++) {
		if (o[i - 1]) tmp[l++] = i;
		for (j = i * 2; j < 10000; j += i) o[j - 1] = 0;
	}

	scanf("%d", &test);
	for (i = 0; i < test; i++) {
		scanf("%d", &num);
		for (a = b = j = 0; tmp[j] <= num / 2; j++) {
			temp = num - tmp[j];
			p = (int *) bsearch(&temp, tmp, l, sizeof(int), cmp);
			if (p) {
				if (!a&&!b) {
					a = tmp[j];
					b = *p;
					mi = abs(a - b);
				} else if (mi > abs(*p - tmp[j])) {
					a = tmp[j];
					b = *p;
					mi = abs(a - b);
				}
			}
		}
		printf("%d %d\n", a, b);
	}
}