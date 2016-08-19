#include <cstdio>

using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", (long long) n * (n + 1) * (n + 2) * (n + 3) / 8);
	}
}