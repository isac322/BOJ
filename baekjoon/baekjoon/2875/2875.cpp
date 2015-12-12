#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k, cnt;
	scanf("%d %d %d", &n, &m, &k);

	if (n >= (m << 1)) {
		cnt = m;
		n -= m << 1;
		m = 0;
	}
	else {
		cnt = n >> 1;
		m -= n >> 1;
		n &= 1;
	}

	k -= m + n;
	printf("%d", cnt - (k > 0 ? (k + 2) / 3 : 0));
}