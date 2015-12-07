#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		int a, b, c;
		scanf("%d", &n);
		double max = 0, re,t;
		int check = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			re = (double)b / (2 * a);
			t = -1 * a*re + b*re + c;
			if (max < t) {
				max = t;
				check = i + 1;
			}
		}
		printf("%d\n", check);
	}
}