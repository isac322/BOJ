#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int map[50][50];
bool visit[50][50];
int sx, sy, ex, ey;

int main() {
	int r, c, t;
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) fill_n(map[i], 50, 10000);

	queue<pair<int, int>> que;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			switch (getchar()) {
				case 'D':
					map[i][j] = 10000;
					ey = i;
					ex = j;
					break;
				case 'S':
					map[i][j] = 10000;
					sy = i;
					sx = j;
					break;
				case 'X':
					map[i][j] = 0;
					visit[i][j] = true;
					break;
				case '.':
					break;
				case '*':
					que.emplace(i, j);
			}
		}
		getchar();
	}

	visit[sy][sx] = visit[ey][ex] = true;
	for (int turn = 0; !que.empty(); turn++) {
		const size_t &len = que.size();
		for (size_t i = 0; i < len; i++) {
			pair<int, int> here = que.front();
			que.pop();

			const int &x = here.second, &y = here.first;
			if (y < 0 || x < 0 || y >= r || x >= c || visit[y][x]) continue;

			visit[y][x] = true;
			map[y][x] = min(map[y][x], turn);

			que.emplace(y + 1, x);
			que.emplace(y - 1, x);
			que.emplace(y, x + 1);
			que.emplace(y, x - 1);
		}
	}

	for (int i = 0; i < r; i++) fill_n(visit[i], c, false);
	que.emplace(sy, sx);

	for (int turn = 0; !que.empty(); turn++) {
		const size_t &len = que.size();
		for (size_t i = 0; i < len; i++) {
			pair<int, int> here = que.front();
			que.pop();

			const int &x = here.second, &y = here.first;
			if (y < 0 || x < 0 || y >= r || x >= c || map[y][x] <= turn || visit[y][x]) continue;
			visit[y][x] = true;
			if (y == ey && x == ex) {
				printf("%d", turn);
				return 0;
			}

			que.emplace(y + 1, x);
			que.emplace(y - 1, x);
			que.emplace(y, x + 1);
			que.emplace(y, x - 1);
		}
	}
	puts("KAKTUS");
}