#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a[4], n[4];
	while (scanf("%d%d%d%d", a, a + 1, a + 2, a + 3), a[0] || a[1] || a[2] || a[3]) {
		int cnt = 0;
		while (a[0] != a[1] || a[1] != a[2] || a[2] != a[3]) {
			for (int i = 0; i < 4; i++) n[i] = abs(a[i] - a[(i + 1) % 4]);
			for (int i = 0; i < 4; i++) a[i] = n[i];
			cnt++;
		}
		printf("%d\n", cnt);
	}
}