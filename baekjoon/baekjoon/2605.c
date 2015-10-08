#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *prev;
	int data;
	struct NODE *next;
}Node;

Node *find(Node *start, int num);

int main() {
	int studentN, student;
	Node *start = NULL, *now, *end = NULL, *tmp;
	int i;
	
	scanf("%d", &studentN);

	scanf("%d", &student);

	now = (Node *)calloc(1, sizeof(Node));
	start = end = now;
	start->data = 1;

	for (i = 1; i < studentN; i++) {
		scanf("%d", &student);
		
		now = (Node *)calloc(1, sizeof(Node));
		
		if (i == student) {
			start->prev = now;
			now->next = start;
			start = now;
		} else if (!student) {
			end->next = now;
			now->prev = end;
			end = now;
		} else {
			tmp = (i + 1) / 2.0 < (double)student ? find(start, i - student - 1) : find(end, -1 * student);
			tmp->next->prev = now;
			now->next = tmp->next;
			tmp->next = now;
			now->prev = tmp;
		}
		now->data = i + 1;
	}

	for (tmp = start; tmp; tmp = tmp->next)	printf("%d ", tmp->data);
}

Node *find(Node *start, int num) {
	if (num > 0) while (num--) start = start->next;
    else while (num++) start = start->prev;
	return start;
}