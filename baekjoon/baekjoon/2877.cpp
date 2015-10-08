#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int len = int(log2(++n));

	for (int i = len - 1; i >= 0; i--) {
		putchar((n >> i) & 1 ? '7' : '4');
	}
}