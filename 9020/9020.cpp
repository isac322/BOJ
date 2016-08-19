#include <stdio.h>

int main() {
	bool arr[10001] = { false };
	int caseN, i, j;
	int in, tmp;
	
	for (i = 2; i < 101; i++) {
		if (arr[i]) continue;
		for (j = i << 1; j < 10001; j += i) arr[j] = true;
	}

	scanf("%d", &caseN);

	while (caseN--) {
		scanf("%d", &in);

		tmp = in / 2;
		if (!arr[tmp]) {
			printf("%d %d\n", tmp, tmp);
			continue;
		}
		for (i = 1; i < tmp; i++) {
			if (!arr[tmp + i] && !arr[tmp - i]) {
				printf("%d %d\n", tmp - i, tmp + i);
				break;
			}
		}
	}
}