#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t, n, d, s;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		s = 0;
		for (int i = 0; i < 6; i++) {
			scanf("%d", &d);
			s += d;
		}

		int cnt = 1;
		for (; s <= n; cnt++, s <<= 2);
		printf("%d\n", cnt);
	}
}