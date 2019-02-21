#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c = 0, d = 0, i;
	char input[100000] = "";
	scanf("%d %d", &a, &b);
	for (i = 0; i < a; i++) {
		scanf("%d", input + i);
		if (i < b) c += input[i];
	}
	d = c;
	for (i = 0; i < a - b; i++) {
		c -= input[i] - input[i + b];
		d = c > d ? c : d;
	}
	printf("%d", d);
}