#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> revMap[20000], map[20000], topological;
vector<bool> visit;
size_t n, current, k, sccCount, sccId[20000];

inline void init() {
	sccCount = 0;
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

bool onlyIn[20000], onlyOut[20000];

inline void SCC() {
	init();
	
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		if (visit[*i]) sccCount++;
		current = *i;
		getSCC(*i);
	}
}

int main() {
	size_t t;
	scanf("%zu", &t);
	while (t--) {
		size_t a, b;
		scanf("%zu%zu", &n, &k);
		
		for (size_t i = 0; i < n; i++) map[i].clear(), revMap[i].clear();
		fill_n(onlyIn, n, true);
		fill_n(onlyOut, n, true);
		
		for (size_t i = 0; i < k; i++) {
			scanf("%zu%zu", &a, &b);
			a--, b--;
			map[a].emplace_back(b);
			revMap[b].emplace_back(a);
		}
		
		SCC();
		
		for (size_t i = 0; i < n; i++) {
			size_t id = sccId[i];
			for (auto next : map[i]) {
				if (sccId[next] != id) onlyIn[id] = onlyOut[sccId[next]] = false;
			}
		}
		
		size_t inCnt = 0, outCnt = 0;
		for (size_t i = 0; i < n; i++) {
			if (onlyIn[i] && i == sccId[i]) inCnt++;
			if (onlyOut[i] && i == sccId[i]) outCnt++;
		}
		printf("%zu\n", sccCount == 1 ? 0 : max(outCnt, inCnt));
	}
}
