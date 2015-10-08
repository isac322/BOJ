#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a = 0, b = 1, n;
	scanf("%d", &n);

	if (n == 0) puts("0");
	else if (n == 1) puts("1");
	else {
		for (int i = 2; i <= n; i++) {
			int t = a + b;
			a = b;
			b = t;
		}

		printf("%d", b);
	}
}