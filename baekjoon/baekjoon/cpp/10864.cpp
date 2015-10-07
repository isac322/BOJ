#include <cstdio>

using namespace std;

int main() {
	int n, m, cnt[1001] = { 0 };
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++) printf("%d\n", cnt[i]);
}