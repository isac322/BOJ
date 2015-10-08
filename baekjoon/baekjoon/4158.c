#include <stdio.h>
#include <memory.h>

long long ma[15625001] = { 0 };
int main() {
	int n, m, t, cnt;
	while (scanf("%d%d", &n, &m) && n && m) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			ma[t >> 6] |= 1LL << (t & 0xFF);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &t);
			cnt += ((ma[t >> 6] >> (t & 0xFF)) & 1LL);
		}
		printf("%d\n", cnt);
		memset(ma, 0, sizeof(long long) * (t >> 6));
	}
}