#include <cstdio>

using namespace std;

int main() {
	while (true) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!a && !b) break;
		printf("%d\n", a - (b - a));
	}
}