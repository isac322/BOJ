#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
	int n, ch;
	scanf("%d\n", &n);
	bitset<26> set;

	while (n--) {
		set.reset();

		while ((ch = getchar()) != 10) if (isalpha(ch)) set[tolower(ch) - 'a'] = true;

		if (set.count() == 26) puts("pangram");
		else {
			printf("missing ");
			for (int i = 0; i < 26; i++) if (!set[i]) putchar(i + 'a');
			puts("");
		}
	}
}