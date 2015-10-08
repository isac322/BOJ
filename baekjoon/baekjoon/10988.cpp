#include <cstdio>

using namespace std;

int main() {
	char str[101];
	int len = 0;
	while ((str[len++] = getchar()) != 10);
	str[--len] = 0;
	bool check = true;
	for (int i = 0; i < (len >> 1); i++) if (str[i] != str[len - i - 1]) check = false;
	putchar(check ? '1' : '0');
}