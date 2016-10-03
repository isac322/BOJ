#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, t;
	scanf("%d%d", &n, &m);
	char *s1 = new char[n + 1];
	char *s2 = new char[m + 1];
	int *p1 = new int[n + 1];
	int *p2 = new int[m + 1];
	scanf("%s%s%d", s1, s2, &t);
	for (int i = n - 1; i >= 0; i--) p1[i] = i + max(0, t - (n - i - 1));
	for (int i = 0; i < m; i++) p2[i] = (n + i) - max(0, t - i);
	int i = 0, j = 0;
	reverse(s1, s1 + n);
	while (i < n && j < m) {
		if (p1[i] < p2[j]) putchar(s1[i++]);
		else if (p1[i] > p2[j]) putchar(s2[j++]);
	}
	while (i < n) putchar(s1[i++]);
	while (j < m) putchar(s2[j++]);
}