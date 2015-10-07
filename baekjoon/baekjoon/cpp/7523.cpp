#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		long long m, n;
		scanf("%lld %lld", &n, &m);
		printf("Scenario #%d:\n%lld\n\n", i, (m - n + 1) * (m + n) / 2);
	}
}