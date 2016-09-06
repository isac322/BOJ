#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

bool map[100][100], visit[100][100];
int l, w;
queue<pair<int, int>> q;

int main() {
	scanf("%d %d\n", &l, &w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) map[i][j] = getchar() == 'L';
		getchar();
	}

	int m = 0, t;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j]) {
				t = 0;
				q.emplace(i, j);

				for (int k = 0; k < l; k++) fill_n(visit[k], w, false);

				size_t len = q.size();
				while (!q.empty()) {
					bool check = false;
					while (len--) {
						auto t = q.front();
						q.pop();

						int &y = t.first, &x = t.second;
						if (y < 0 || y > l || x > w || x < 0 || !map[y][x] || visit[y][x]) continue;
						check = visit[y][x] = true;

						q.emplace(y - 1, x);
						q.emplace(y + 1, x);
						q.emplace(y, x + 1);
						q.emplace(y, x - 1);
					}
					len = q.size();
					if (check) t++;
				}
				m = max(t, m);
			}
		}
	}
	printf("%d", m - 1);
}