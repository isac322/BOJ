#include <stdio.h>
int a, max = 1;
void h(int a) {
	if (a == 1) return;
	if (a % 2) {
		a = a * 3 + 1;
		if (max<a)
			max = a;
	} else {
		a /= 2;
		if (max<a)
			max = a;
	}
	if (a == 1) return;
	else h(a);
}
int main() {
	while (scanf("%d", &a) && a) {
		max = a;
		h(a);
		printf("%d\n", max);
	}
}