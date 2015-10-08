#include <stdio.h>

int main() {
	char s1[101], s2[101];
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		gets(s1);
		gets(s2);
		for (int j = 0; s1[j]; j++) if (s1[j] != s2[j]) cnt++;
		printf("Hamming distance is %d.\n", cnt);
	}
}