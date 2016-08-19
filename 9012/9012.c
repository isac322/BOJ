#include <stdio.h>

int main() {
	char str[51];
	int n, l, r;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		l = r = 0;
		gets(str);
		for (int j = 0; str[j]; j++) {
			if (str[j] == '(') l++;
			else r++;
		}
		if (l != r) puts("NO");
		else {
			l = r = 0;
			for (int j = 0; str[j]; j++) {
				if (str[j] == '(') l++;
				else if (l > 0) l--;
			}
			if (l == 0) puts("YES");
			else puts("NO");
		}
	}
}