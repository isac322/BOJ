#include <cstdio>
#include <cstring>

char str[5000001];
int main() {
	unsigned long long a, b, c;
	scanf("%llu %llu", &a, &b);
	while (b) {
		c = a%b;
		a = b;
		b = c;
	}
	memset(str, '1', a);
	puts(str);
}