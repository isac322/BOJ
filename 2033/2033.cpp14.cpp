#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 10; i < n; i *= 10) {
		if (n % i / (i / 10) > 4) n += i;
		n -= n % i;
	}
	printf("%d", n);
}