#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	double x, y, m;
	scanf("%lf %lf%d", &x, &y, &n);
	m = 1000 / y*x;
	while (n--) {
		scanf("%lf %lf", &x, &y);
		m = min(m, 1000 / y*x);
	}
	printf("%lf", m);
}