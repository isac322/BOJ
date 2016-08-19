#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, a, b;
vector<bool> visit;
vector<vector<int>> inEdge, outEdge, group(1);
vector<int> arr;

void dfs(int index) {
	if (visit[index]) return;
	visit[index] = true;

	for (int t : outEdge[index]) dfs(t);
	arr.emplace_back(index);
}

void scc(int index) {
	if (visit[index]) return;
	visit[index] = true;

	for (int t : inEdge[index]) scc(t);
	group.back().emplace_back(index);
}

int main() {
	scanf("%d%d", &v, &e);
	inEdge.resize(v);
	outEdge.resize(v);
	visit.resize(v, false);
	while (e--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		inEdge[b].emplace_back(a);
		outEdge[a].emplace_back(b);
	}
	for (int i = 0; i < v; i++) dfs(i);
	fill(visit.begin(), visit.end(), false);
	for (auto i = arr.rbegin(); i != arr.rend(); i++) {
		scc(*i);
		if (!group.back().empty()) group.emplace_back();
	}
	group.pop_back();
	printf("%zd\n", group.size());
	for (auto &b : group) sort(b.begin(), b.end());
	sort(group.begin(), group.end());
	for (auto &v : group) {
		for (int t : v) printf("%d ", t + 1);
		puts("-1");
	}
}