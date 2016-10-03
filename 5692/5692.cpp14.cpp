#include <cstdio>

using namespace std;

int main() {
	int n, c, a[] = { 1,2,6,24,120 };
	while (true) {
		c = 0;
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; n; n /= 10, i++) c += (n % 10)*a[i];
		printf("%d\n", c);
	}
}