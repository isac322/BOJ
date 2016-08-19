#include <cstdio>

int main() {
	int r, c;
	char b[11] = "";
	scanf("%d %d\n", &r, &c);
	while (r--) {
		int i = c;
		while (i--) b[i] = getchar();
		getchar();
		puts(b);
	}
}