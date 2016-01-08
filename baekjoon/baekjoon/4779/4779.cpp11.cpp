#include <cstdio>

void print(int t) {
	if (t == 0) {
		putchar('-');
		return;
	}
	int n = 1;
	for (int i = 0; i < t - 1; i++) n *= 3;
	print(t - 1);
	for (int i = 0; i < n; i++) putchar(' ');
	print(t - 1);
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		print(n);
		puts("");
	}
}