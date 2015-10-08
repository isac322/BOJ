#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int t = 1;
	while (true) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) break;

		printf("Triangle #%d\n", t);
		if (a == -1) {
			if (b >= c) {
				puts("Impossible.");
			}
			else {
				printf("a = %.3lf\n", sqrt(c*c - b*b));
			}
		}
		else if (b == -1) {
			if (a >= c) {
				puts("Impossible.");
			}
			else {
				printf("b = %.3lf\n", sqrt(c*c - a*a));
			}
		}
		else {
			printf("c = %.3lf\n", sqrt(a*a + b*b));
		}

		puts("");
		t++;
	}
}