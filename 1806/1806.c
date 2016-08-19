#include <stdio.h>

int main() {
	int N, S, tmp = 0, min = 100000, check, war = 1;
	int i = 0, j = 0;
	int mat[100000] = { 0 };


	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++) {
		scanf("%d", mat + i);
	}

	for (i = 0; i < N; tmp = 0, check = 1, i++) {
		for (j = i; j < N; j++) {
			tmp += mat[j];
			if (tmp >= S) {
				check = 0;
				break;
			}
		}
		if (check) continue;
		else if (min > j - i + 1) {
			war = 0;
			min = j - i + 1;
		}
	}

	printf("%d", war ? 0 : min);
}