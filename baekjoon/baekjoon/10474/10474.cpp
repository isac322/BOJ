#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	while (scanf("%d%d",&a,&b), a || b) {
		printf("%d %d / %d\n", a / b, a%b, b);
	}
}