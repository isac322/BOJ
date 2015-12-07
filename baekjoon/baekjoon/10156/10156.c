#include <stdio.h>

int main() {
	int k, n, m;
	scanf("%d %d %d", &k, &n, &m);
	k *= n;
	printf("%d", k > m ? k - m : 0);
}