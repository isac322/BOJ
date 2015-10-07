#include <cstdio>

using namespace std;

int main() {
	int cnt = 0, n, mi = 1;
	scanf("%d", &n);
	while (n) {
		if (n < mi) mi = 1;
		n -= mi++;
		cnt++;
	}
	printf("%d", cnt);
}