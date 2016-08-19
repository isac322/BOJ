#include <cstdio>
#include <algorithm>

char str[10000001];
int main() {
	unsigned long long a, b, c;
	scanf("%llu %llu", &a, &b);
	while (b) {
		c = a%b;
		a = b;
		b = c;
	}
	std::fill_n(str, a, '1');
	puts(str);
}