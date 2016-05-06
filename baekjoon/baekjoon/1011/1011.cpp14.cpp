#include <cstdio>

int main() {
	int t, a, b;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &a, &b);
		b -= a;

		int cnt = 0, i = 1;
		for (; b > i * 2; i++, cnt += 2) b -= i * 2;
		cnt += (b / i);
		if (b % i) cnt++;
		printf("%d\n", cnt);
	}
}