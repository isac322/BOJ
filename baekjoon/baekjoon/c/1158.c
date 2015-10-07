#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE * prev;
	int num;
	struct NODE *next;
}node;

int main() {
	int n, d;
	int i;
	node *start = NULL, *now = NULL, *end = NULL, *tmp;

	scanf("%d %d", &n, &d);
	for (i = 0; i < n; i++) {
		now = (node *) calloc(1, sizeof(node));
		if (!i) end = start = now;
		now->num = i + 1;
		end->next = now;
		now->prev = end;
		now->next = start;
		start->prev = now;
		end = now;
	}

	printf("<");
	now = start;
	while (now->num != now->next->num) {
		for (i = 0; i < d - 1; i++) now = now->next;
		printf("%d, ", now->num);
		tmp = now->next;
		now->prev->next = now->next;
		now->next->prev = now->prev;
		free(now);
		now = tmp;
	}
	printf("%d>", now->num);
}