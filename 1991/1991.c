#include <stdio.h>

char tree[26][2];

void pre(char i) {
	printf("%c", i + 'A');
	if (tree[i][0] != -1) pre(tree[i][0]);
	if (tree[i][1] != -1) pre(tree[i][1]);
}
void post(char i) {
	if (tree[i][0] != -1) post(tree[i][0]);
	if (tree[i][1] != -1) post(tree[i][1]);
	printf("%c", i + 'A');
}
void in(char i) {
	if (tree[i][0] != -1) in(tree[i][0]);
	printf("%c", i + 'A');
	if (tree[i][1] != -1) in(tree[i][1]);
}

int main() {
	int n, i;
	char str[6];
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(str);
		tree[str[0] - 'A'][0] = str[2] == '.' ? -1 : str[2] - 'A';
		tree[str[0] - 'A'][1] = str[4] == '.' ? -1 : str[4] - 'A';
	}
	pre(0);
	puts("");
	in(0);
	puts("");
	post(0);
	puts("");
}