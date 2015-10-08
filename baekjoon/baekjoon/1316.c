#include <stdio.h>
#include <memory.h>

int main() {
	int n, k, a[26], j;
	char b[101];

	scanf("%d\n", &n);
	k = n;
	while(n--) {
		gets(b);
		memset(a, 0, 26*4);
		for (j = 0; b[j]; j++) {
			if (!a[b[j] - 97] || b[j] == b[j - 1]) a[b[j] - 97]++;
			else {
				k--;
				break;
			}
		}
	}
	printf("%d", k);
}