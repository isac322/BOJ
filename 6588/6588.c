#include <stdio.h>
#include <math.h>

int check(int num) {
	if (num == 1) return 0;
	else if (num == 2) return 1;
	else if (!(num & 1)) return 0;

	int i = 2;
	int s = (int) sqrt((double) num);
	for (; i <= s; i++) {
		if (!(num%i)) break;
	}
	return i == (s + 1) ? 1 : 0;
}

int main() {
	int i, in;

	while (scanf("%d", &in) && in) {
		for (i = 1; i < in / 2; i++) {
			if (check(i + 1) && check(in - i - 1)) {
				printf("%d = %d + %d\n", in, i + 1, in - i - 1);
				break;
			}
		}
		if (i == in / 2) puts("Goldbach's conjecture is wrong.");
	}
}