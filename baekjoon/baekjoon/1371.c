#include <stdio.h>
#include <stdlib.h>

typedef struct D {
	int cnt;
	char c;
}f;

int cmp(const void* c, const void *d) {
	f *a = (f*) c, *b = (f*) d;
	if (a->cnt == b->cnt) return a->c - b->c;
	else return b->cnt - a->cnt;
}

int main() {
	f cnt[26] = { 0 };
	char t;
	for (int i = 0; i < 26; i++) cnt[i].c = i + 'a';
	while ((t = getchar()) != EOF) if (t != ' ' || t != 10) cnt[t - 'a'].cnt++;
	qsort(cnt, 26, sizeof(f), cmp);
	for (int i = 0; cnt[0].cnt == cnt[i].cnt; i++) putchar(cnt[i].c);
}