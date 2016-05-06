#include <cstdio>

using namespace std;

int main() {
	int n, t = 0;
	scanf("%d", &n);
	for (; n; n >>= 1) t += n & 1;
	printf("%d", t == 1);
}