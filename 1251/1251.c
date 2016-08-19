#include <stdio.h>
#include <string.h>

char word[51] = "", an[51] = "", tmp[51] = "";

void rev(int i, int len) {
	for (int j = i; j < i + len; j++) {
		tmp[len - j - 1 + i + i] = word[j];
	}
}

int main() {
	gets(word);
	strcpy(an, word);
	int i, j, len = strlen(word);
	for (i = 0; i < len - 2; i++) {
		rev(0, i + 1);
		for (j = i + 1; j < len - 1; j++) {
			rev(i + 1, j - i);
			rev(j + 1, len - j - 1);
			if (strcmp(tmp, an) == -1) strcpy(an, tmp);
		}
	}
	puts(an);
}