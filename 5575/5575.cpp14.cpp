#include <cstdio>

int main() {
	int h, m, s, h1, m1, s1;
	for (int i = 0; i < 3; i++) {
		scanf("%d%d%d%d%d%d", &h, &m, &s, &h1, &m1, &s1);
		s += m * 60 + h * 60 * 60;
		s1 += m1 * 60 + h1 * 60 * 60;
		s1 -= s;
		printf("%d %d %d\n", s1 / 60 / 60, s1 / 60 % 60, s1 % 60);
	}
}