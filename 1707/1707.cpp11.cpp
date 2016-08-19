#include <cstdio>
#include <vector>

using namespace std;

int t, v, e, a, b;
vector<int> map[20000];
char color[20000];

bool dfs(int index, char isRed) {
	color[index] = isRed;
	for (auto v : map[index]) {
		if (color[v] == -1 && !dfs(v, 1 - isRed)) return false;
		if (color[v] == isRed) return false;
	}

	return true;
}

inline bool bipartiteTest() {
	for (int i = 0; i < v; i++) if (color[i] == -1 && !dfs(i, 0)) return false;
	return true;
}

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &v, &e);

		for (int i = 0; i < v; i++) map[i].clear();
		fill_n(color, v, -1);

		while (e--) {
			scanf("%d%d", &a, &b);
			a--, b--;
			map[a].emplace_back(b);
			map[b].emplace_back(a);
		}
		puts(bipartiteTest() ? "YES" : "NO");
	}
}