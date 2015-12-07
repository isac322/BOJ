#include <cstdio>

using namespace std;

int main() {
	int n;
	int c = 1;
	while (true) {
		scanf("%d", &n);
		if (!n) break;

		int n1 = n * 3;
		printf("%d. %s %d\n", c, n1 & 1 ? "odd" : "even", ((n1 + 1) >> 1) / 3);
		c++;
	}
}