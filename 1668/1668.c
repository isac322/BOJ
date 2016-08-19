#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, p, c, rc = 1, lc = 1, rmax, lmax;
	scanf("%d", &n);
	int *tr = (int *) calloc(n, sizeof(int));
	scanf("%d", tr);
	lmax = tr[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", tr + i);
		if (tr[i] > lmax) {
			lmax = tr[i];
			lc++;
		}
	}
	rmax = tr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (tr[i] > rmax) {
			rmax = tr[i];
			rc++;
		}
	}
	printf("%d\n%d", lc, rc);
}