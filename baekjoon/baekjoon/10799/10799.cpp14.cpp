#include <cstdio>

char c;
int sum;

int solve() {
	if (c == ')') {
		c = getchar();
		return 1;
	}
	int ret = 0;
	while (c == '(') c = getchar(), ret += solve();
	c = getchar();
	sum += ret + 1;
	return ret ? ret : 1;
}

int main() {
	c = getchar();
	while (c == '(') c = getchar(), solve();
	printf("%d", sum);
}