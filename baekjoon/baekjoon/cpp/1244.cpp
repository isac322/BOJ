#include <bitset>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	bitset<100> bit;

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t) bit.set(i);
	}

	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == 1) {
			for (int i = b - 1; i < n; i += b) bit.flip(i);
		}
		else {
			int idx = b - 1;

			bit.flip(idx);
			for (int i = 1; idx - i >= 0 && idx + i < n && bit[idx - i] == bit[idx + i]; i++) {
				bit.flip(idx - i);
				bit.flip(idx + i);
			}
		}
	}

	int t = 20;
	for (int i = 0; i < n; i++) {
		if (!t) {
			puts("");
			t = 19;
		}
		else t--;
		printf("%d ", bit[i] ? 1 : 0);
	}
}