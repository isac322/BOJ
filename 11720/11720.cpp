#include <cstdio>

int main() {
	int n, sum = 0, t;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		t = getchar() - '0';
		sum += t;
	}
	printf("%d", sum);
}