#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


namespace ConvexHull {
	struct Point {
		short x, y;
		double angleInSin = 0.0;

		bool operator<(const Point &val) const {
			if (angleInSin == val.angleInSin) return x < val.x;
			else return angleInSin < val.angleInSin;
		}

		Point() { }

		Point(short x, short y) : x(x), y(y) { }

		Point(const Point &val) : x(val.x), y(val.y), angleInSin(val.angleInSin) { }
	};

	vector<Point> points;


	inline void gen_angle(const Point &base) {
		for (auto &p : points) {
			p.angleInSin = atan2(p.y - base.y, p.x - base.x) * 180 / M_PI;
		}
	}

	inline int ccw(const Point &a, const Point &b, const Point &c) {
		return int(b.x) * c.y - int(c.x) * b.y - (int(a.x) * c.y - int(c.x) * a.y) + int(a.x) * b.y - int(b.x) * a.y;
	}

	vector<Point *> hull;

	vector<Point *> &convex_hull() {
		Point mostLeft = points[0];

		for (auto &d : points) {
			if (mostLeft.y > d.y || (mostLeft.y == d.y && mostLeft.x > d.x)) {
				mostLeft = d;
			}
		}

		gen_angle(mostLeft);
		sort(points.begin(), points.end());


		hull.clear();

		for (auto &p : points) {
			while (hull.size() >= 2 && ccw(*hull[hull.size() - 2], *hull.back(), p) <= 0) {
				hull.pop_back();
			}

			hull.emplace_back(&p);
		}

		return hull;
	}
}

using namespace ConvexHull;

int dist(const Point *const s, const Point *const e) {
	return int(s->x - e->x) * (s->x - e->x) + int(s->y - e->y) * (s->y - e->y);
}

int main() {
	int n;
	scanf("%d", &n);

	points.resize(n);
	for (int i = 0; i < n; i++) scanf("%hd%hd", &points[i].x, &points[i].y);

	convex_hull();

	int maximum = 0;
	int s_index = 0, e_index = 1;

	while (e_index < hull.size()) {
		while (dist(hull[s_index], hull[e_index]) < dist(hull[s_index + 1], hull[e_index])) s_index++;

		maximum = max(maximum, dist(hull[s_index], hull[e_index]));

		e_index++;
	}

	printf("%.9Lf", sqrtl(maximum));
}