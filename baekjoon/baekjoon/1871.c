#include <stdio.h>
#include <math.h>

int main() {
	char a[9];
	int t, s,n;
	scanf("%d", &t);
	getchar();
	while (t--) {
		s = (getchar() - 'A') * 676;
		s += (getchar() - 'A') * 26;
		s += getchar() - 'A';
		scanf("%d", &n);
		gets(a);
		puts(abs(s + n) > 100 ? "not nice" : "nice");
	}
}