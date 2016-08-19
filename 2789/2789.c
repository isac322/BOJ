#include <stdio.h>
#include <string.h>

int main() {
	char a;
	char *str = "CAMBRIDGE";

	while ((a = getchar()) != 10) {
		if (!strchr(str, a))
			putchar(a);
	}
}