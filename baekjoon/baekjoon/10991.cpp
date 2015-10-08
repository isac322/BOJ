#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) putchar(' ');
		for (int j = 0; j < i; j++) printf("* ");
		puts("");
	}
}