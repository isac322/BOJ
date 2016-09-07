#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> map[100000], revMap[100000], topological;
vector<bool> visit;
size_t n, current, sccId[100000];
size_t m, t, a, b;

void topologicalSort(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : map[idx]) topologicalSort(v);
	
	topological.emplace_back(idx);
}

void makeSCC(size_t idx) {
	if (!visit[idx]) return;
	visit[idx] = false;
	
	for (auto v : revMap[idx]) makeSCC(v);
	sccId[idx] = current;
}

inline void SCC() {
	topological.clear();
	visit.resize(n, false);
	
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		current = *i;
		makeSCC(*i);
	}
}

bool onlyIn[100000];

int main() {
	scanf("%zu", &t);
	while (t--) {
		scanf("%zu%zu", &n, &m);
		
		for (size_t i = 0; i < n; i++) map[i].clear(), revMap[i].clear();
		fill_n(onlyIn, n, true);
		
		while (m--) {
			scanf("%zu%zu", &a, &b);
			a--, b--;
			map[a].emplace_back(b);
			revMap[b].emplace_back(a);
		}
		
		SCC();
		
		for (size_t i = 0; i < n; i++) {
			size_t id = sccId[i];
			for (auto next : map[i]) {
				if (sccId[next] != id) onlyIn[sccId[next]] = false;
			}
		}
		
		size_t cnt = 0;
		for (size_t i = 0; i < n; i++) if (onlyIn[i] && sccId[i] == i) cnt++;
		
		printf("%zu\n", cnt);
	}
}