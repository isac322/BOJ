#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char str[2000001];
	fill_n(str, n, '1');
	fill_n(str + n, n - 1, '0');
	str[n + n - 1] = 0;
	puts(str);
}