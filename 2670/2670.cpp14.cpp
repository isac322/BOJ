#include <cstdio>
#include <cmath>

int main() {
	int n;
	double m, h, t;
	scanf("%d%lf", &n, &t);
	m = h = log2(t);
	while (--n) {
		scanf("%lf", &t);
		t = log2(t);
		h = fmax(t, h + t);
		m = fmax(m, h);
	}
	printf("%.3lf", pow(2, m));
}