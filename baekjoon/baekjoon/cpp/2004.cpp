#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long n, m;
	scanf("%lld%lld", &n, &m);
	long long dif = n - m, a = 0, b = 0;

	for (long long i = 2; i <= n; i *= 2) a += n / i;
	for (long long i = 5; i <= n; i *= 5) b += n / i;
	for (long long i = 2; i <= dif; i *= 2) a -= dif / i;
	for (long long i = 5; i <= dif; i *= 5) b -= dif / i;
	for (long long i = 2; i <= m; i *= 2) a -= m / i;
	for (long long i = 5; i <= m; i *= 5) b -= m / i;

	printf("%lld", min(a, b));
}