#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct P {
	char name[31];
	int candiN;
	int timeA;
	char check;
}Person;

int cmp(const void *a, const void *b) {
	Person c = *(Person *)a, d = *(Person *)b;
	int t = c.candiN - d.candiN;

	if (!c.check) return t;
	if (!t) return c.timeA - d.timeA;
	else return t;
}

int main() {
	int n, m;
	int memN, i, j;
	char member[100000][31] = { "" }, tmp[31];
	Person *p = NULL;

	while (1) {
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		p = (Person *)calloc(m, sizeof(Person));

		getchar();
		for (memN = 0; memN < n; memN++) {
			gets(member[memN]);
		}
		for (i = 0; i < m; i++) {
			scanf("%s %s", p[i].name, tmp);
			p[i].timeA = i;
			getchar();
			for (j = 0; j < memN; j++) if (!strcmp(member[j], tmp)) break;
			if (j == memN) {
				p[i].check = 1;
				strcpy(member[memN++], tmp);
			}
			p[i].candiN = j;
		}

		qsort(p, m, sizeof(Person), cmp);
		for (j = 0; j < m; j++) puts(p[j].name);
	}
}