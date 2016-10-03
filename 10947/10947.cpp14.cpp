#include <cstdio>

int main() {
	int n, x[26], y[26], cnt = 0;

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (getchar() == '.') continue;
			x[cnt] = i;
			y[cnt] = j;
			cnt++;
		}
		getchar();
	}

	int ans = 0;

	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			for (int k = j + 1; k < cnt; k++) {
				if ((x[j] - x[i])*(y[k] - y[i]) - (y[j] - y[i])*(x[k] - x[i]) == 0) ans++;
			}
		}
	}

	printf("%d\n", ans);
}