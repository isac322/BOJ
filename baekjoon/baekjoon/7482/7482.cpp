#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		double d;
		scanf("%lf", &d);
		printf("%.10lf\n", d / 6);
	}
}