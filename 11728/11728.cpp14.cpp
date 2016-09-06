#include <cstdio>

int n, m, a[1000000], b[1000000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < m; i++) scanf("%d", b + i);

	const int *ae = a + n, *be = b + m;
	int *i = a, *j = b;

	while (i < ae || j < be) {
		if (i == ae) for (; j < be; j++) printf("%d ", *j);
		else if (j == be) for (; i < ae; i++) printf("%d ", *i);
		else if (*i < *j) {
			printf("%d ", *i);
			i++;
		}
		else {
			printf("%d ", *j);
			j++;
		}
	}
}