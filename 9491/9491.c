#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct P {
	char name[31];
	char candi[31];
	int candiN;
	int time;
}person;

int cmp(const void *a, const void *b) {
	person c = *(person *)a, d = *(person *)b;

	if (c.candiN == d.candiN) return c.time - d.time;
	else return c.candiN - d.candiN;
}

int main() {
	int n, m;
	person *p;

	while (1) {
		int memN, supportN, j;
		char member[100000][31] = { "" };
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		p = (person *)calloc(100000, sizeof(person));

		getchar();
		for (memN = 0; memN < n; memN++) {
			gets(member[memN]);
		}
		for (supportN = 0; supportN < m; supportN++) {
			scanf("%s %s", p[supportN].name, p[supportN].candi);
			p[supportN].time = supportN;
			getchar();
		}

		for (int i = 0; i < memN; i++) {
			for (int j = 0; j < supportN; j++) {
				if (!strcmp(member[i], p[j].candi)) {
					puts(p[j].name);
					p[j].candi[0] = p[j].name[0] = '\0';
				}
			}
		}

		memN = 0;
		for (int i = 0; i < supportN; i++) {
			if (p[i].candi[0]) {
				for (j = 0; j < memN; j++) if (!strcmp(member[j], p[i].candi)) break;
				if (j == memN) strcpy(member[memN++], p[i].candi);
				p[i].candiN = j;
			}
		}

		qsort(p, supportN, sizeof(person), cmp);
		for (int i = 0; i < supportN; i++) {
			if (p[i].candi[0]) {
				puts(p[i].name);
			}
		}
	}
}