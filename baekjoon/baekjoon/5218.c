#include <stdio.h>

int main() {
	int n, i;
	char a[31], b[31];
	scanf("%d", &n);

	while (n--) {
		scanf("%s %s", a, b);
		printf("Distances: ");
		for (i = 0; i < a[i]; i++) printf("%d ", b[i] - a[i] + (a[i]<=b[i] ? 0 : 26));
		puts("");
	}
}