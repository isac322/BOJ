#include <stdio.h>
#include <stdlib.h>

typedef struct PERSON {
	char name[15];
	int dd;
	int mm;
	int yyyy;
}person;

int cmp(const void *a, const void *b) {
	person *p1 = (person*)a, *p2 = (person*)b;

	if (p1->yyyy == p2->yyyy) {
		if (p1->mm == p2->mm) return p1->dd - p2->dd;
		else return p1->mm - p2->mm;
	} else
		return p1->yyyy - p2->yyyy;
}

int main() {
	int caseN = 0;
	int i = 0;
	person *p = NULL;

	scanf("%d", &caseN);

	p = (person*)calloc(caseN, sizeof(person));

	for (i = 0; i < caseN; i++) {
		scanf("%s %d %d %d", p[i].name, &p[i].dd, &p[i].mm, &p[i].yyyy);
	}

	qsort(p, caseN, sizeof(person), cmp);

	printf("%s\n%s", p[caseN - 1].name, p[0].name);
}