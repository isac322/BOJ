#include <stdio.h>

char arr[50][50];
int pos[50] = { 0 };
char e;

char calc(char node) {
	if (node == e) return 0;
	int re = 0, len = pos[node], i = 0;
	if (len == 0) return 1;
	for (; i < len; i++) re += calc(arr[node][i]);
	return re;
}

int main() {
	char n, r, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == -1) r = i;
		else arr[a][pos[a]++] = i;
	}
	scanf("%d", &e);
	printf("%d", calc(r));
}