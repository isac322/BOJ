#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> revMap[100000], map[100000], topological;
vector<bool> visit;
size_t n, k, sccId[100000], current;

inline void init() {
	visit.resize(n, false);
	topological.clear();
}

void topologicalSort(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : map[idx]) topologicalSort(v);
	
	topological.emplace_back(idx);
}

void getSCC(size_t idx) {
	if (!visit[idx]) return;
	visit[idx] = false;
	
	for (auto v : revMap[idx]) getSCC(v);
	sccId[idx] = current;
}

bool onlyOut[100000];

inline void SCC() {
	init();
	
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		current = *i;
		getSCC(*i);
	}
}

void dfs(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto next : map[idx]) dfs(next);
}

int main() {
	size_t t;
	scanf("%zu", &t);
	while (t--) {
		size_t a, b;
		scanf("%zu%zu", &n, &k);
		
		for (size_t i = 0; i < n; i++) map[i].clear(), revMap[i].clear();
		
		for (size_t i = 0; i < k; i++) {
			scanf("%zu%zu", &a, &b);
			map[a].emplace_back(b);
			revMap[b].emplace_back(a);
		}
		
		SCC();
		
		fill_n(onlyOut, n, true);
		for (size_t i = 0; i < n; i++) {
			size_t id = sccId[i];
			for (auto next : map[i]) if (sccId[next] != id) onlyOut[sccId[next]] = false;
		}
		
		size_t root;
		for (size_t i = 0; i < n; i++) {
			if (onlyOut[i] && sccId[i] == i) {
				root = i;
				break;
			}
		}
		dfs(root);
		
		bool check = true;
		for (size_t i = 0; i < n; i++) {
			if (!visit[i]) {
				check = false;
				break;
			}
		}
		fill(visit.begin(), visit.end(), false);
		
		if (check) {
			for (size_t i = 0; i < n; i++) if (sccId[i] == root) printf("%zu\n", i);
		}
		else puts("Confused");
		puts("");
	}
}