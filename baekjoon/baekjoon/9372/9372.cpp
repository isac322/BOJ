#include <cstdio>

using namespace std;

int main() {
	int t, n, m, i;
	char tmp[10];
	scanf("%d\n", &t);

	while (t--) {
		scanf("%d %d\n", &n, &m);
		for (i = 0; i < m; i++) gets(tmp);
		printf("%d\n", n - 1);
	}
}