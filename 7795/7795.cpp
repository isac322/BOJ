#include <stdio.h>
#include <algorithm>

using namespace std;

int a[20001] = { 0 }, b[20001] = { 0 };

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 0; i < m; i++) scanf("%d", b + i);
		sort(a, a + n);
		sort(b, b + m);

		int a_pos = 0, b_pos = 0, cnt = 0;

		while (a_pos != n) {
			while (b_pos != m && a[a_pos] > b[b_pos]) b_pos++;
			cnt += b_pos;
			a_pos++;
		}
		printf("%d\n", cnt);
	}
}