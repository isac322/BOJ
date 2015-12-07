#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
char wheel[101];

int cmp(int pos, const char *str) {
	for (int i = 0; i < m; i++) {
		char &ch = wheel[(i + pos) % n];

		if (ch == str[i]) continue;
		else if (ch < str[i]) return -1;
		else return 1;
	}

	return 0;
}

int main() {
	int t;
	char x[10], y[10], ch;
	scanf("%d%", &t);

	while (t--) {
		scanf("%d%d%", &n, &m);

		for (int i = 0; i < m; i++) scanf("%hhd", x + i);
		for (int i = 0; i < m; i++) scanf("%hhd", y + i);

		for (int i = 0; i < n; i++) scanf("%hhd", wheel + i);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (cmp(i, x) >= 0 && cmp(i, y) <= 0) cnt++;
		}

		printf("%d\n", cnt);
	}
}