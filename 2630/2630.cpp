#include <cstdio>
#include <algorithm>

using namespace std;

bool map[128][128];
int n;

typedef pair<int, int> INTP;

INTP solve(int r, int c, int size) {
	const bool &start = map[r][c];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i + r][j + c] != start) {
				int half = size >> 1;
				INTP a = solve(r, c, half);
				INTP b = solve(r + half, c, half);
				INTP c1 = solve(r, c + half, half);
				INTP d = solve(r + half, c + half, half);

				return make_pair(a.first + b.first + c1.first + d.first, a.second + b.second + c1.second + d.second);
			}
		}
	}

	if (start == 0) return make_pair(1, 0);
	else return make_pair(0, 1);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			map[i][j] = t ? 1 : 0;
		}
	}

	INTP ret = solve(0, 0, n);
	printf("%d\n%d", ret.first, ret.second);
}