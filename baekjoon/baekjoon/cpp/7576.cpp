#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<short, short> SHRTPR;

char map[1000][1000] = { 0 };
int main() {
	int n, m;
	queue< SHRTPR > que;
	scanf("%d%d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%hhd", map[i] + j);
			if (map[i][j] == 1) que.push(make_pair(i, j));
		}
	}

	int day = 0;
	for (; que.size() > 0; day++) {

		for (int i = que.size(); i--;) {
			SHRTPR q = que.front();
			que.pop();
			short &r = q.first, &c = q.second;

			r--;
			if (r >= 0 && map[r][c] == 0) {
				que.push(q);
				map[r][c] = 1;
			}

			r += 2;
			if (r < n && map[r][c] == 0) {
				que.push(q);
				map[r][c] = 1;
			}

			r--, c--;
			if (c >= 0 && map[r][c] == 0) {
				que.push(q);
				map[r][c] = 1;
			}

			c += 2;
			if (c < m && map[r][c] == 0) {
				que.push(q);
				map[r][c] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d", day - 1);
}