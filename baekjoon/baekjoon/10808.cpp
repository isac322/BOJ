#include <stdio.h>

int main() {
	char count[26] = { 0 }, str[101];
	gets(str);
	for (int i = 0; str[i]; i++) count[str[i] - 'a']++;
	for (int i = 0; i < 26; i++) printf("%d ", count[i]);
}