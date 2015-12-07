#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long a, b, k;
	scanf("%lld%lld%lld", &k, &a, &b);

	if (a < 0 && b > 0) printf("%lld", -a / k + b / k + 1);
	else if (a > 0) {
		if (b != 0) printf("%lld", b / k - a / k + (a % k ? 0 : 1ll));
		else printf("%lld", -a / k + 1);
	}
	else {
		if (a != 0) printf("%lld", -a / k + b / k + (b % k ? 0 : 1ll));
		else printf("%lld", b / k + 1);
	}
}