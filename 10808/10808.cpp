#include <stdio.h>

int main() {
	char count[26] = { 0 }, t;
	while ((t = getchar()) != 10) {
		count[t - 'a']++;
	}
	for (int i = 0; i < 26; i++) printf("%d ", count[i]);
}