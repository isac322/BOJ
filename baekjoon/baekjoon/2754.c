#include <stdio.h>
#include <string.h>

int main() {
	char a[3] = "";

	gets(a);
	if (!strcmp(a, "A+")) puts("4.3");
	else if (!strcmp(a, "A0")) puts("4.0");
	else if (!strcmp(a, "A-")) puts("3.7");
	else if (!strcmp(a, "B+")) puts("3.3");
	else if (!strcmp(a, "B0")) puts("3.0");
	else if (!strcmp(a, "B-")) puts("2.7");
	else if (!strcmp(a, "C+")) puts("2.3");
	else if (!strcmp(a, "C0")) puts("2.0");
	else if (!strcmp(a, "C-")) puts("1.7");
	else if (!strcmp(a, "D+")) puts("1.3");
	else if (!strcmp(a, "D0")) puts("1.0");
	else if (!strcmp(a, "D-")) puts("0.7");
	else if (!strcmp(a, "F")) puts("0.0");
}