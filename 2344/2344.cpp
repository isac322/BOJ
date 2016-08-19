#include <cstdio>
#include <algorithm>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;

bool room[1000][1000];
int dx[][4] = {
	{ 1,-1,0,0 },
	{ 0,0,-1,1 }
};
int dy[][4] = {
	{ 0,0,1,-1 },
	{ -1,1,0,0 }
};
int next_dir[][4] = {
	{ LEFT,RIGHT,UP,DOWN },
	{ DOWN,UP,RIGHT,LEFT }
};

int n, m, t;

inline int getNum(int r, int c) {
	if (c == -1) return r + 1;
	else if (r == n) return n + c + 1;
	else if (c == m) return n + m + (n - r);
	else if (r == -1) return (n << 1) + m + (m - c);
}

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			room[i][j] = t == 1;
		}
	}

	int r = 0, c = 0, type;
	int direction = LEFT;

	for (int i = 0; i < n; i++) {
		r = i;
		c = 0;
		direction = LEFT;

		while (!(r < 0 || r >= n || c < 0 || c >= m)) {
			type = room[r][c] ? 1 : 0;

			r = r + dy[type][direction];
			c = c + dx[type][direction];
			direction = next_dir[type][direction];
		}

		printf("%d ", getNum(r, c));
	}

	for (int i = 0; i < m; i++) {
		r = n - 1;
		c = i;
		direction = DOWN;

		while (!(r < 0 || r >= n || c < 0 || c >= m)) {
			type = room[r][c] ? 1 : 0;

			r = r + dy[type][direction];
			c = c + dx[type][direction];
			direction = next_dir[type][direction];
		}

		printf("%d ", getNum(r, c));
	}

	for (int i = n - 1; i >= 0; i--) {
		r = i;
		c = m - 1;
		direction = RIGHT;

		while (!(r < 0 || r >= n || c < 0 || c >= m)) {
			type = room[r][c] ? 1 : 0;

			r = r + dy[type][direction];
			c = c + dx[type][direction];
			direction = next_dir[type][direction];
		}

		printf("%d ", getNum(r, c));
	}

	for (int i = m - 1; i >= 0; i--) {
		r = 0;
		c = i;
		direction = UP;

		while (!(r < 0 || r >= n || c < 0 || c >= m)) {
			type = room[r][c] ? 1 : 0;

			r = r + dy[type][direction];
			c = c + dx[type][direction];
			direction = next_dir[type][direction];
		}

		printf("%d ", getNum(r, c));
	}
}