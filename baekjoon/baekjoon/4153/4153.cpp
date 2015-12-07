#include <cstdio>

using namespace std;

int main() {
	int a, b, c;
	while (true) {
		scanf("%d%d%d", &a, &b, &c);
		if (a + b + c == 0) break;

		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		if (b > c) {
			int t = b;
			b = c;
			c = t;
		}

		puts((c*c == a*a + b*b) ? "right" : "wrong");
	}
}