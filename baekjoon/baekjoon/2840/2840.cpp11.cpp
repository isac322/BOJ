#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int k, n, t, j = 0;
	char str[25], c;
	fill(str, str + 25, '?');
	scanf("%d %d%*c", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %c%*c", &t, &c);
		j = (j + t) % n;
		if (str[j] != '?' && str[j] != c) {
			puts("!");
			return 0;
		}
		else str[j] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] == str[j] && str[i] != '?') {
				puts("!");
				return 0;
			}
		}
	}
	for (t = n; t--; j--) {
		putchar(str[j]);
		if (!j) j = n;
	}
}