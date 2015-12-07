#include <stdio.h>
#include <string.h>

char arr[26], match[98];

void solve(char root, char length, char start) {
	char node = arr[root];
	char left = match[node] - start;

	if (left != 0) solve(root + 1, left, start);
	if (length != match[node] - start + 1) {
		solve(root + left + 1, length - left - 1, match[node] + 1);
	}

	putchar(node);
}

int main() {
	char str[26];

	while (~scanf("%s %s\n", arr, str)) {
		int len = strlen(arr);

		for (int i = 0; i < len; i++) match[str[i]] = i;

		solve(0, len, 0);
		puts("");
	}
}