#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};

inline long long ccw(const Point &a, const Point &b, const Point &c) {
	long long x1 = a.x, x2 = b.x, x3 = c.x;

	return x2 * c.y - x3 * b.y - (x1 * c.y - x3 * a.y) + x1 * b.y - x2 * a.y;
}

int main() {
	Point o, p, pp;
	int n;
	long long sum = 0;
	scanf("%d\n%d %d\n%d %d", &n, &o.x, &o.y, &p.x, &p.y);
	for (int i = 2; i < n; i++) {
		scanf("%d %d", &pp.x, &pp.y);
		sum += ccw(o, p, pp);
		p = pp;
	}
	if (sum < 0LL) sum = -sum;
	printf("%lld.%d", sum >> 1LL, sum & 1LL ? 5 : 0);
}