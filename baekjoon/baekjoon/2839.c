#include <stdio.h>

int main() {
	int a, b, cnt = 0;
	scanf("%d", &b);
	a = b;
	for (; a > 4; a -= 5, cnt++);
	for (; b > a && a % 3; a += 5, cnt--);
	for (; a > 0; a -= 3, cnt++);
	printf("%d", a ? -1 : cnt);
}