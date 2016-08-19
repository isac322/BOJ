#include <stdio.h>
#include <memory.h>

int main() {
	char card[1000] = { 0 };
	int n, pos = 0;
	scanf("%d", &n);
	memset(card, 1, sizeof(char)*n);
	for (int i = 0; i < n; i++) {
		while (!card[pos]) pos = (pos + 1) % n;
		printf("%d ", pos + 1);
		if (i == n - 1) break;
		card[pos] = 0;
		pos = (pos + 1) % n;
		while (!card[pos]) pos = (pos + 1) % n;
		pos = (pos + 1) % n;
	}
}