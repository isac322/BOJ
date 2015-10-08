#include <stdio.h>

int main() {
	int num[100] = { 0 };
	int n, prev = 0, t, pos = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		pos = (pos + prev) % n;
		while (num[pos]) pos = (pos + 1) % n;
		prev = num[pos] = t;
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d ", num[i]);
}