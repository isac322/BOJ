#include <cstdio>

int main() {
	int t = 0, c;
	while ((c = getchar()) != -1) if (c == 10) t++;
	printf("%d", t);
}