#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	char str[11];

	int i1, i2;
	for (int i = 0; i < n; i++) {
		gets(str);

		if (!strcmp(str, "KBS1")) i1 = i;
		else if (!strcmp(str, "KBS2")) i2 = i;
	}

	if (i2 < i1) i2++;

	for (int i = 0; i < i1; i++) putchar('1');
	for (int i = 0; i < i1; i++) putchar('4');
	for (int i = 0; i < i2; i++) putchar('1');
	for (int i = 0; i < i2 - 1; i++) putchar('4');
}