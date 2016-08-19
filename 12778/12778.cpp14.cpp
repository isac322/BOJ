#include <cstdio>

int main() {
	char t;
	int n, m, q;
	scanf("%d\n", &n);
	while (n--) {
		scanf("%d %c\n", &m, &t);
		while (m--) {
			if (t == 'C') printf("%d ", getchar() - 'A' + 1);
			else {
				scanf("%d", &q);
				printf("%c ", 64 + q);
			}
			getchar();
		}
		puts("");
	}
}