#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char str1[31], str2[31];
	scanf("%s %s", str1, str2);

	int p1, p2;
	for (int i = 0; str1[i]; i++) {
		for (int j = 0; str2[j]; j++) {
			if (str1[i] == str2[j]) {
				p1 = i;
				p2 = j;
				goto OUT;
			}
		}
	}
	OUT:;

	size_t len1 = strlen(str1), len2 = strlen(str2);
	for (int i = 0; i < len2; i++) {
		if (i == p2) puts(str1);
		else {
			for (int j = 0; j < len1; j++) {
				if (j == p1) putchar(str2[i]);
				else putchar('.');
			}
			puts("");
		}
	}
}