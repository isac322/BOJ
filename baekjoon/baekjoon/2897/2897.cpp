#include <cstdio>
#include <algorithm>

using namespace std;

char map[51][51];

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; i++) gets(map[i]);

	int cnt[5] = { 0 };

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (map[i][j] != '#' && map[i][j + 1] != '#' && map[i + 1][j] != '#' && map[i + 1][j + 1] != '#') {
				int num = 0;
				if (map[i][j] == 'X') num++;
				if (map[i][j + 1] == 'X') num++;
				if (map[i + 1][j] == 'X') num++;
				if (map[i + 1][j + 1] == 'X') num++;

				cnt[num]++;
			}
		}
	}
	
	for (int i = 0; i < 5; i++) printf("%d\n", cnt[i]);
}