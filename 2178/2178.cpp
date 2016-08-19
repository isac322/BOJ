#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	bool mat[102][102] = { 0 }, visit[102][102] = { 0 };
	pair<char, char> p(1, 1), t;
	int n, m, i, j;
	char prev[101] = "";
	scanf("%d %d\n", &n, &m);
	for (i = 1; i <= n; i++) {
		gets(prev);
		for (j = 1; j <= m; j++) mat[i][j] = prev[j - 1] - '0';
	}
	queue< pair<char, char> > que;
	int cnt = 1, tmp, popcnt = 1;
	que.push(p);
	while (1) {
		for (tmp = i = 0; i < popcnt; i++) {
			p = que.front();
			if (p.first == n && p.second == m) {
				printf("%d", cnt);
				return 0;
			}
			que.pop();
			if (mat[p.first - 1][p.second] && !visit[p.first - 1][p.second]) {
				tmp++;
				t.first = p.first - 1;
				t.second = p.second;
				que.push(t);
				visit[p.first - 1][p.second] = 1;
			}
			if (mat[p.first + 1][p.second] && !visit[p.first + 1][p.second]) {
				tmp++;
				t.first = p.first + 1;
				t.second = p.second;
				que.push(t);
				visit[p.first + 1][p.second] = 1;
			}
			if (mat[p.first][p.second - 1] && !visit[p.first][p.second - 1]) {
				tmp++;
				t.first = p.first;
				t.second = p.second - 1;
				que.push(t);
				visit[p.first][p.second - 1] = 1;
			}
			if (mat[p.first][p.second + 1] && !visit[p.first][p.second + 1]) {
				tmp++;
				t.first = p.first;
				t.second = p.second + 1;
				que.push(t);
				visit[p.first][p.second + 1] = 1;
			}
		}
		popcnt = tmp;
		cnt++;
	}
}