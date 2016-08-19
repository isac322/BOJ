#include <cstdio>
#include <cstring>
#include <algorithm>

char n[100001], t[11];

int main() {
	scanf("%s\n%s", n, t);
	char *p = n;
	int c = 0;
	while (p = strstr(p, t)) {
		c++;
		p++;
	}
	printf("%d", c);
}