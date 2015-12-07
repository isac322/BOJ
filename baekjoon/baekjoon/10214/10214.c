#include <stdio.h>

int main() {
	int t, a, b, s = 0, s1 = 0, i;
	
	for (scanf("%d", &t); t--; s = s1 = 0) {
		for (i = 0; i < 9; i++) {
			scanf("%d %d", &a, &b);
			s += a;
			s1 += b;
		}
		puts(s>s1 ? "Yonsei" : s == s1 ? "Korea" : "Draw");
	}
}