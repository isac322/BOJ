#include <stdio.h>

int main() {
	int a, b, re, i = 1;
	char op[3];

	while (1) {
		scanf("%d %s %d", &a, op, &b);
		switch (op[0]) {
			case '<':
				if (op[1]) re = a <= b;
				else re = a < b;
				break;
			case '>':
				if (op[1]) re = a >= b;
				else re = a > b;
				break;
			case '=': re = a == b; break;
			case '!': re = a != b; break;
			case 'E': return 0;
		}
		printf("Case %d: %s\n", i, re ? "true" : "false");
		i++;
	}
}