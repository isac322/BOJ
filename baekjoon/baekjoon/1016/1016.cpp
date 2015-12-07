#include <stdio.h>

const int maxn = 10000010;
bool check[maxn] = { false }, prime[maxn] = { false };

int main() {
	long long a, b, i, j, t, dif;

	scanf("%lld %lld", &a, &b);
	for (i = 2; i < 3164; i++) if (!prime[i]) for (j = 2 * i; j < maxn; j += i) prime[j] = true;

	dif = b - a + 1;

	for (i = 2; i < maxn; i++) {
		t = i*i;
		if (b < t) break;
		if (prime[i]) continue;

		if (a%t == 0) j = 0;
		else j = t - a%t;
		for (; j < dif; j += t) check[j] = true;
	}

	int cnt = 0;
	for (i = 0; i < dif; i++) if (!check[i]) cnt++;
	printf("%d\n", cnt);
}