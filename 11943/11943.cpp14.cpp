#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d", min(a + d, b + c));
}