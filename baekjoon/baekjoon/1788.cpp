#include <cstdio>

using namespace std;

int main() {
	int n, t;
	scanf("%d", &t);
	n = t < 0 ? -t : t;

	int p = 1, pp = 0;
	for (int i = 2; i <= n; i++) {
		int t = p + pp;
		pp = p;
		p = t % 1000000000;
	}

	if (t == 0) puts("0");
	else if (t < 0 && !(n & 1)) puts("-1");
	else puts("1");

	printf("%d", t == 0 ? 0 : p);
}