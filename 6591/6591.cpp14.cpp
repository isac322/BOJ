#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long n, k, val;
	while (true) {
		scanf("%lld%lld", &n, &k);
		if ((n + k) == 0) break;
		k = min(k, n - k);
		if (!k) puts("1");
		else {
			val = n;
			for (long long r = 1; r < k; r++) {
				val = (val*(n - r)) / (r + 1);
			}
			printf("%lld\n", val);
		}
	}
}