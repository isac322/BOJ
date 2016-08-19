#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *a;
	int num;
}Char;

int cmp(const void *a, const void *b) {
	return strcmp(((Char *)a)->a, ((Char *)b)->a);
}

int main() {
	int M, N;
	int i = 0, j;
	Char p[100000] = { 0 }, state;
	char a[100000][21] = { 0 };

	scanf("%d %d\n", &M, &N);

	for (; i < M; i++) {
		p[i].a = a + i;
		gets(p[i].a);
		p[i].num = i + 1;
	}

	qsort(p, M, sizeof(Char), cmp);
	state.a = (char *)calloc(21, sizeof(char));
	for (i = 0; i < N; i++) {
		gets(state.a);
		if (state.a[0] >= '0' && state.a[0] <= '9') puts(a[atoi(state.a) - 1]);
		else printf("%d\n", ((Char *)bsearch(&state, p, M, sizeof(Char), cmp))->num);
	}
}