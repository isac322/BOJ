#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE * prev;
	int num;
	struct NODE *next;
}node;

node *move(node *N, int n) {
	if (n < 0) 	while (n++) N = N->prev;
	else while (n--) N = N->next;
	return N;
}

int main() {
	int n, d, cnt, c;
	int i;
	node *start = NULL, *now = NULL, *end = NULL, *tmp;

	scanf("%d %d", &n, &d);
	cnt = n;
	for (i = 0; i < n; i++) {
		now = (node *)calloc(1, sizeof(node));
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
	c = d > n / 2 ? 0 : 1;
	while (now->num != now->next->num) {
		now = move(now, c ? d - 1 : d - cnt-- - 1);
		printf("%d, ", now->num);
		tmp = now->next;
		now->prev->next = now->next;
		now->next->prev = now->prev;
		now = tmp;
	}
	printf("%d>", now->num);
}