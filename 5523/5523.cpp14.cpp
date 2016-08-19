#include <cstdio>

int main() {
	int n, a, b, s1 = 0, s2 = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		if (a > b) s1++;
		else if (a != b) s2++;
	}
	printf("%d %d", s1, s2);
}