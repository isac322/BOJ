#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	n = a + b + c + d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", max(n, a + b + c + d));
}