#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long x, y, w, s;
	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
	if (w * 2 <= s) printf("%lld", x * w + y * w);
	else if (s <= w) printf("%lld", max(x, y) * s + ((x + y) & 1 ? w - s : 0));
	else printf("%lld", x > y ? (x - y) * w + y * s : (y - x) * w + x * s);
}