#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		printf("Pairs for %d:", n);
		if (n > 2) printf(" 1 %d", n - 1);
		for (int i = 2; i <= (n - 1) >> 1; i++) {
			printf(", %d %d", i, n - i);
		}
		puts("");
	}
}