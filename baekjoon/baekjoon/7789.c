#include <stdio.h>

int main() {
	int a, b;
	int i, j;
	char st[8];
	scanf("%d %d", &a, &b);
	sprintf(st + 1, "%d", a);
	st[0] = b + '0';
	b = a;
	a = atoi(st);
	for (i = 2; i < a; i++) if (!(a % i)) break;
	for (j = 2; j < b; j++) if (!(b % j)) break;
	if (a == i && b == j) puts("Yes");
	else puts("No");
}