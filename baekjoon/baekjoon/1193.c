#include <stdio.h>

int main() {
	int in;
	int i = 1;

	scanf("%d", &in);
	for (; in > i; in -= i++);
	printf("%d/%d", i % 2 ? i - in + 1 : in, i % 2 ? in : i - in + 1);
}