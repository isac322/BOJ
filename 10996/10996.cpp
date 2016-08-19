#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n << 1; i++) {
		if (i & 1) putchar(' ');
		for (int j = i & 1; j < n; ++j) if ((i & 1) != 0 == (j & 1)) printf("* ");
		puts("");
	}
}