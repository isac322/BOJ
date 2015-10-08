#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int score[2] = { 100,100 };
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a < b) score[0] -= b;
		else if (a>b) score[1] -= a;
	}
	printf("%d\n%d", score[0], score[1]);
}