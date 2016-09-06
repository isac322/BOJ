#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char str[1000001];
	fill_n(str, n, '1');
	str[n] = 0;
	printf("%s", str);
	fill_n(str, n - 1, '0');
	str[n - 1] = 0;
	puts(str);
}