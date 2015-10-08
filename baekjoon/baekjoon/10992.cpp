#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i < t; i++) putchar(' ');
	puts("*");
	for (int i = 1; i < t - 1; ++i) {
		for (int j = 1; j < t - i; j++) putchar(' ');
		putchar('*');
		for (int j = 1; j < (i << 1); j++) putchar(' ');
		puts("*");
	}
	if (t > 1) for (int i = 1; i < (t << 1); i++) putchar('*');
}