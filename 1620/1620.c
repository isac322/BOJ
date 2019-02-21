#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char a[21];
	int num;
}Char;

int cmp(const void *a, const void *b) {
	return strcmp(((Char *)a)->a, ((Char *)b)->a);
}

int main() {
	int M, N;
	int i = 0, j;
	Char p[100000] = { 0 };
	char a[100000][21] = { 0 }, state[21] = "";

	scanf("%d %d\n", &M, &N);

	for (; i < M; i++) {
		gets(p[i].a);
		p[i].num = i + 1;
		strcpy(a[i], p[i].a);
	}

	qsort(p, M, sizeof(Char), cmp);
	for (i = 0; i < N; i++) {
		gets(state);
		if (state[0] >= '0' && state[0] <= '9') puts(a[atoi(state) - 1]);
		else printf("%d\n", ((Char *)bsearch(state, p, M, sizeof(Char), cmp))->num);
	}
}