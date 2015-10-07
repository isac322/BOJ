#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, cnt[5] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (!a || !b) cnt[0]++;
		else if (a > 0) {
			if (b > 0) cnt[1]++;
			else cnt[4]++;
		}
		else {
			if (b > 0) cnt[2]++;
			else cnt[3]++;
		}
	}
	for (int i = 1; i <= 4; i++) printf("Q%d: %d\n", i, cnt[i]);
	printf("AXIS: %d", cnt[0]);
}