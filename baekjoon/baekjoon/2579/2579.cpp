#include <stdio.h>

int t;
int v[301] = { 0 };
int s[301][2] = { 0 };
bool ch[301][2] = { 1, 1, 1, 1, 1, 1 };

int sum(int n, bool b) {
	int a = ch[n - 1][1] ? s[n - 1][1] : sum(n - 1, 1);
	int c = ch[n - 2][0] ? s[n - 2][0] : sum(n - 2, 0);
	if (b) a = 0;
	ch[n][b] = 1;
	s[n][b] = (a > c ? a : c) + v[n];
	return s[n][b];
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", v + i);
		s[i][0] = s[i][1] = v[i];
	}
	s[2][0] += v[1];
	printf("%d\n", sum(t, 0));
}