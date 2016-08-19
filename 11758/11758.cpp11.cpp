#include <cstdio>

using namespace std;

int x1, x2, x3, yy2, y2, y3;

inline int ccw() {
	return x2 * y3 - x3 * y2 - (x1 * y3 - x3 * yy2) + x1 * y2 - x2 * yy2;
}

int main() {
	scanf("%d%d%d%d%d%d", &x1, &yy2, &x2, &y2, &x3, &y3);
	printf("%d", ccw() == 0 ? 0 : ccw() < 0 ? -1 : 1);
}