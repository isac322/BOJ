#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int maxdiff = 0, classN = 0, stuN = 0, score[50] = { 0 };
	int i = 0, j = 0;

	scanf("%d", &classN);

	for (i = 1; i <= classN; maxdiff = 0, i++) {
		memset(score, 0, sizeof(int)* stuN);
		scanf("%d", &stuN);
		for (j = 0; j < stuN; j++)
			scanf("%d", score + j);
		qsort(score, stuN, sizeof(int), cmp);
		for (j = 0; j < stuN - 1; j++) {
			if (maxdiff < score[j + 1] - score[j])
				maxdiff = score[j + 1] - score[j];
		}

		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i, score[stuN-1], score[0], maxdiff);
	}
}