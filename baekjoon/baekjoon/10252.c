#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int height, width;
		scanf("%d %d", &height, &width);

		puts("1");
		for (int i = 0; i < width; i++) printf("(0,%d)\n", i);
		for (int i = 1; i < height; i++) printf("(%d,%d)\n", i, width - 1);

		for (int x = width - 2; x > 0; x -= 2) {
			for (int y = height - 1; y > 0; y--) printf("(%d,%d)\n", y, x);
			for (int y = 1; y < height; y++) printf("(%d,%d)\n", y, x - 1);
		}

		if (width % 2 == 0) {
			for (int y = height - 1; y > 0; y--) printf("(%d,0)\n", y);
		}
	}
}