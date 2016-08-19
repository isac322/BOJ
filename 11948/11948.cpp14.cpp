#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a[4], b[2];
	for (int i = 0; i < 4; i++) scanf("%d", a + i);
	scanf("%d%d", b, b + 1);
	sort(a, a + 4);
	printf("%d", a[1] + a[2] + a[3] + max(b[0], b[1]));
}