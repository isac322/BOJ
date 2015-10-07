#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		double d, a, b, f;
		scanf("%d %lf %lf %lf %lf", &n, &d, &a, &b, &f);

		printf("%d %.2lf\n", n, d / (b + a)*f);
	}
}