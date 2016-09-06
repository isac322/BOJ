#include <stdio.h>
#include <math.h>

int check(int num) {
	if (num == 1) return 0;
	else if (num == 2) return 1;
	else if (!(num & 1)) return 0;

	int i = 2;
	int s = (int)sqrt((double) num);
	for (; i <= s; i++) {
		if (!(num%i)) break;
	}
	return i == (s + 1) ? 1 : 0;
}

int main() {
	int caseN, i;
	int in, tmp;

	scanf("%d", &caseN);

	while (caseN--) {
		scanf("%d", &in);

		tmp = in / 2;
		if (check(tmp)) {
			printf("%d %d\n", tmp, tmp);
			continue;
		}
		for (i = 1; i < in / 2; i++) {
			if (check(tmp + i) && check(tmp - i)) {
				printf("%d %d\n", tmp - i, tmp + i);
				break;
			}
		}
	}
}