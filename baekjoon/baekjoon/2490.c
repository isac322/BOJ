#include <stdio.h>

int main() {
	int i, j;
	int sum = 0, tmp;

	for (i = 0; i < 3; sum = 0, i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		switch (sum) {
		case 4:
			puts("E");
			break;
		case 3:
			puts("A");
			break;
		case 2:
			puts("B");
			break;
		case 1:
			puts("C");
			break;
		case 0:
			puts("D");
			break;
		}
	}
}