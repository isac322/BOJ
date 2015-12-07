#include <stdio.h>

int main() {
	char tmp[21], start, check, t;
	while (1) {
		scanf("%s", tmp);
		start = tmp[0];
		if (start == '*') break;
		check = 1;
		if (getchar() != 10) {
			while (1) {
				scanf("%s", tmp);
				if (tmp[0] != start && tmp[0] - 32 != start && tmp[0] + 32 != start) check = 0;
				if (getchar() == 10) break;
			}
		}
		puts(check ? "Y" : "N");
	}
}