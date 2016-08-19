#include <cstdio>

int main() {
	int n, t = 0;
	scanf("%d", &n);

	for (; n; n >>= 1) {
		t <<= 1;
		t += n & 1;
	}
	printf("%d", t);
}