#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i & 1) putchar(' ');
		for (int j = 0; j < n; ++j) printf("* ");
		puts("");
	}
}