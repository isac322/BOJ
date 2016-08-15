#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	for (scanf("%d%d%d", &a, &b, &c); a + b + c; scanf("%d%d%d", &a, &b, &c)) {
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		if (a + b <= c) puts("Invalid");
		else if (a == b && b == c) puts("Equilateral");
		else if (a == b || a == c || b == c) puts("Isosceles");
		else puts("Scalene");
	}
}