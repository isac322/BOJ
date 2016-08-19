#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	double a, b, c, m, n, o;
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &m, &n, &o);
	double t = min({ a / m, b / n, c / o });
	printf("%lf %lf %lf", a - m*t, b - n*t, c - o*t);
}