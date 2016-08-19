#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[26];

int main() {
	bool clockwise = true;
	int q, n, prev = 0, diff, crrtPos = 25, c, r;
	char op[6];
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d", op, &n);

		diff = n - prev;
		r = diff % 26;
		c = diff / 26;

		for (int i = 0; i < 26; i++) cnt[i] += c;
		for (int i = 0; i < r; i++) {
			if (clockwise) {
				crrtPos = (crrtPos + 1) % 26;
			}
			else {
				crrtPos = (26 + crrtPos - 1) % 26;
			}
			cnt[crrtPos]++;
		}

		if (op[0] == 'U') {
			scanf("%s", op);
			printf("%d\n", cnt[op[0] - 'a']);
		}
		else clockwise = !clockwise;

		prev = n;
	}
}