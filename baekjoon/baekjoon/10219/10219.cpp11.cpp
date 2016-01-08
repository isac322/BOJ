#include <cstdio>

int main() {
	int t, w, h;
	char g[11][12];
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &h, &w);
		for (int i = 0; i < h; i++) gets(g[i]);
		for (int i = h - 1; i >= 0; i--) puts(g[i]);
	}
}