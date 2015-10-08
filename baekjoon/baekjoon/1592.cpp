#include <stdio.h>

using namespace std;

int main() {
	int n, m, l, cnt[1000] = {0}, ball = 0, total = 0;
	scanf("%d%d%d", &n, &m, &l);

	while (++cnt[ball] != m) {
		if (cnt[ball] & 1) ball = (n + ball - l) % n;
		else ball = (ball + l) % n;
		total++;
	}

	printf("%d", total);
}