#include <stdio.h>

int main() {
	char check[51] = { 0 };
	int cnt = 0, n, m, t, point = 1;
	int i, j, tmp, tmp2;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &t);
		if (t != point) {
			tmp = tmp2 = 0;
			j = t;
			do {
				j--;
				if (j == 0) j = n;
				if (!check[j]) tmp++;
			} while (point != j);
			j = t;
			do {
				j++;
				if (j == n + 1) j = 1;
				if (!check[j]) tmp2++;
			} while (point != j);
			cnt += tmp > tmp2 ? tmp2 : tmp;
		}

		j = t + 1;
		if (j == n + 1) j = 1;
		for (; check[j]; j++) {
			if (j == n) j = 0;
		}
		check[t] = 1;
		point = j;
	}
	printf("%d", cnt);
}