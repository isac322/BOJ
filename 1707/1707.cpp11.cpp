#include <cstdio>
#include <vector>

using namespace std;

int t, v, e, a, b;
vector<int> map[20000];
bool visit[20000], color[20000];

bool dfs(int index, bool isRed) {
	if (visit[index]) return true;
	visit[index] = true;

	color[index] = isRed;
	for (auto v : map[index]) {
		if (!dfs(v, !isRed)) return false;
		if (color[v] == color[index]) return false;
	}

	return true;
}

inline bool bipartiteTest() {
	for (int i = 0; i < v; i++) if (!dfs(i, false)) return false;
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &v, &e);
		for (int i = 0; i < v; i++) map[i].clear();
		fill_n(visit, v, false);
		fill_n(color, v, false);
		while (e--) {
			scanf("%d%d", &a, &b);
			a--, b--;
			map[a].emplace_back(b);
			map[b].emplace_back(a);
		}
		puts(bipartiteTest() ? "YES" : "NO");
	}
}