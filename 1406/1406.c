#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *prev;
	char data;
	struct NODE *next;
}Node;

Node *head, *tail, *current, *ne;

int main() {
	head = (Node *) calloc(1, sizeof(Node));
	current = tail = (Node *) calloc(1, sizeof(Node));
	head->next = tail;
	tail->prev = head;
	char t, in[5];
	while ((t = getchar()) != 10) {
		ne = (Node *) calloc(1, sizeof(Node));
		ne->data = t;
		ne->next = current;
		ne->prev = current->prev;
		current->prev->next = ne;
		current->prev = ne;
	}
	int n;
	scanf("%d\n", &n);
	while (n--) {
		gets(in);
		switch (in[0]) {
			case 'P':
				ne = (Node *) calloc(1, sizeof(Node));
				ne->data = in[2];
				ne->next = current;
				ne->prev = current->prev;
				current->prev->next = ne;
				current->prev = ne;
				break;
			case 'L':
				if (current->prev != head) current = current->prev;
				break;
			case 'D':
				if (current != tail) current = current->next;
				break;
			case 'B':
				if (current->prev != head) {
					ne = current->prev;
					ne->prev->next = current;
					current->prev = current->prev->prev;
					free(ne);
				}
				break;
		}
	}
	for (current = head->next; current != tail; current = current->next) printf("%c", current->data);
}