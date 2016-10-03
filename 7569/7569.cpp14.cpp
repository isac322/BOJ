#include <cstdio>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

typedef char POINT;
typedef tuple<POINT, POINT, POINT> XYZ;

char map[100][100][100] = {0};

int main() {
	int n, m, h;
	queue<XYZ> que;
	scanf("%d%d%d", &m, &n, &h);

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%hhd", map[i][j] + k);
				if (map[i][j][k] == 1) que.emplace(POINT(i), POINT(j), POINT(k));
			}
		}
	}

	int day = 0;
	for (; !que.empty(); day++) {

		for (size_t i = que.size(); i--;) {
			XYZ q = que.front();
			que.pop();
			POINT &x = get<0>(q), &y = get<1>(q), &z = get<2>(q);

			x--;
			if (x >= 0 && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}

			x += 2;
			if (x < n && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}

			x--, y--;
			if (y >= 0 && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}

			y += 2;
			if (y < m && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}

			y--, z--;
			if (z >= 0 && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}

			z += 2;
			if (z < h && map[x][y][z] == 0) {
				que.push(q);
				map[x][y][z] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (map[i][j][k] == 0) {
					puts("-1");
					return 0;
				}
			}
		}
	}
	printf("%d", day - 1);
}