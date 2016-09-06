#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char id;
	char testScore[101];
	int cnt;
	int lastTime;
	int sum;
}ID;

int cmp(const void *a, const void *b) {
	ID *c = (ID *) a, *d = (ID *) b;
	if (c->sum == d->sum) {
		if (c->cnt == d->cnt) {
			return c->lastTime - d->lastTime;
		} else return c->cnt - d->cnt;
	} else return d->sum - c->sum;
}

int main() {
	int T, i;
	int teams, tests, id, m;
	int t, n, s;

	for (scanf("%d", &T); T--;) {
		ID ids[101] = { { 0, { 0 }, { 0 }, 0, 0 } };

		scanf("%d %d %d %d", &teams, &tests, &id, &m);
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &t, &n, &s);
			if (!ids[t].id) ids[t].id = t;
			ids[t].cnt++;
			if (ids[t].testScore[n] < s) {
				ids[t].sum += s - ids[t].testScore[n];
				ids[t].testScore[n] = s;
			}
			ids[t].lastTime = i;
		}
		qsort(ids + 1, teams, sizeof(ID), cmp);
		for (i = 1; i <= teams; i++) if (ids[i].id == id) break;
		printf("%d\n", i);
	}
}