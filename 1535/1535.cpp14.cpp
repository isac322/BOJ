#include <cstdio>
#include <algorithm>

using namespace std;

int d[20][101], n, w[20], v[20];

int s(int i, int W) {
	if (i < 0) return 0;
	int &p = d[i][W];
	if (p != -1) return p;
	if (w[i] >= W) return p = s(i - 1, W);
	return p = max(s(i - 1, W), s(i - 1, W - w[i]) + v[i]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		fill_n(d[i], 101, -1);
		scanf("%d", w + i);
	}
	for (int i = 0; i < n; i++) scanf("%d", v + i);
	printf("%d\n", s(n - 1, 100));
}