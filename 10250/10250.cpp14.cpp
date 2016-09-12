#include <cstdio>

int main() {
	int t, h, b;
	for (scanf("%d", &t); t--;) {
		scanf("%d %d %d", &h, &b, &b);
		printf("%d%02d\n", b%h ? b%h : h, b / h + (b%h ? 1 : 0));
	}
}