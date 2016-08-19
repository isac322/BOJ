#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	char n1[13] = "", n2[13] = "";

	sprintf(n1, "%d%d", a, b);
	sprintf(n2, "%d%d", c, d);

	printf("%lld", atoll(n1) + atoll(n2));
}