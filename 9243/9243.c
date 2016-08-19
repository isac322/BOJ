#include <stdio.h>

int main() {
	int n, t;
	char a[1001], b[1001];
	scanf("%d\n", &n);
	gets(a);
	gets(b);
	t = n & 1;
	for (int i = 0; a[i]; i++) {
		if (((a[i] - '0') ^ t) != (b[i] - '0')) {
			puts("Deletion failed");
			return;
		}
	}
	puts("Deletion succeeded");
}