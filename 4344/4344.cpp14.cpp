#include <cstdio>

int main() {
	int t, n, arr[1000], s, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		c = s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			s += arr[i];
		}
		double av = double(s) / n;
		for (int i = 0; i < n; i++) if (arr[i] > av) c++;
		printf("%.3lf%%\n", double(c) / n * 100);
	}
}