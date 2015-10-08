#include <stdio.h>

int main() {
	char bo[3999972] = { 1, 1 };
	int pos = 0, prime[283146] = { 0 };
	for (int i = 2; i <= 2000; i++) if (!bo[i]) for (int j = i << 1; j <= 3999971; j += i) bo[j] = 1;
	for (int i = 2; i <= 3999971; i++) if (!bo[i]) prime[pos++] = i;
	int n, cnt = 0, tmp = 2;
	scanf("%d", &n);
	int i = 0, j = 1;
	while (i != j && j <= pos && i <= pos) {
		if (tmp == n) {
			cnt++;
			tmp = prime[++i];
			j = i + 1;
		} else if (tmp < n) tmp += prime[j++];
		else tmp -= prime[i++];
	}
	printf("%d", cnt);
}