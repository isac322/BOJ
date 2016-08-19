#include <cstdio>

int main() {
	int n, arr[] = { 500, 100, 50, 10, 5, 1 }, cnt = 0;
	scanf("%d", &n);
	n = 1000 - n;
	for (auto v : arr) while (n >= v) n -= v, cnt++;
	printf("%d", cnt);
}