#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int i = 1, j;
	int **tri = NULL;
	
	scanf("%d", &num);
	tri = (int **)calloc(num, sizeof(int));

	for (; i <= num; i++) {
		tri[i - 1] = (int *)calloc(i, sizeof(int));
		for (j = 0; j < i; j++) scanf("%d", &tri[i - 1][j]);
	}

	while (num--) for (i = 0; i < num; i++) tri[num - 1][i] += tri[num][i] > tri[num][i + 1] ? tri[num][i] : tri[num][i + 1];
	printf("%d", tri[0][0]);
}