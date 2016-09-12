#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w;
		scanf("%d %d", &h, &w);

		puts("1");
		for (int i = 0; i < w; i++) printf("(0,%d)\n", i);
		for (int i = 1; i < h; i++) printf("(%d,%d)\n", i, w - 1);

		for (int x = w - 2; x > 0; x -= 2) {
			for (int y = h - 1; y > 0; y--) printf("(%d,%d)\n", y, x);
			for (int y = 1; y < h; y++) printf("(%d,%d)\n", y, x - 1);
		}

		if (w % 2 == 0) {
			for (int y = h - 1; y > 0; y--) printf("(%d,0)\n", y);
		}
	}
}