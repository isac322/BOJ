#include <stdio.h>

int main() {
	int n;
	int a[50][3] = { 0 };
	int i= 0, j, k;
	
	scanf("%d", &n);
	for (; i < n; i++) scanf("%d %d", *(a + i), *(a + i) + 1);
	for (i = 0; i < n; i++) {
		for (k = 1, j = 0; j < n; j++) if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) k++;
		printf("%d ", k);
	}
}