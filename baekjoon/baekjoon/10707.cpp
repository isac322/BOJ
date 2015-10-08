#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d, p;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &p);
	printf("%d", min(a*p, d*(p > c ? p - c : 0) + b));
}