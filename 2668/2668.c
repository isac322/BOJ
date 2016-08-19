#include <stdio.h>

int main() {
	char check[2][111] = { 0 }, num[111] = { 0 }, flag = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", num + i);
		check[0][num[i] - 1] = 1;
		check[1][num[i] - 1]++;;
	}
	for (int i = 0; i < n; i++) if (!check[0][i]) check[1][num[i] - 1]--;
	do {
		flag = 0;
		for (int i = 0; i < n; i++) {
			if (check[0][i] && !check[1][i]) {
				flag = 1;
				check[0][i] = 0;
				if (!(--check[1][num[i] - 1])) {
					i = -1;
					flag = 0;
					continue;
				}
			}
		}
	} while (flag);
	int cnt = 0;
	for (int i = 0; i < n; i++) if (check[0][i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) if (check[0][i]) printf("%d\n", i + 1);
}