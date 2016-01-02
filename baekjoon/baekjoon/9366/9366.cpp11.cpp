#include <cstdio>
#include <algorithm>

int main() {
	int t, a[3], c = 1;
	scanf("%d", &t);
	for (; c <= t; c++) {
		scanf("%d %d %d", a, a + 1, a + 2);
		std::sort(a, a + 3);
		printf("Case #%d: ", c);
		if (a[0] + a[1] <= a[2]) puts("invalid!");
		else if (a[0] == a[1] && a[0] == a[2]) puts("equilateral");
		else if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2]) puts("scalene");
		else puts("isosceles");
	}
}