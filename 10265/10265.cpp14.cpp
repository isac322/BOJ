#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<size_t>> revMap;
vector<size_t> topological;
size_t parent[1000], map[1000];
bool visit[1000];
size_t n, current, k;

size_t find(size_t p) {
	size_t &q = parent[p];
	if (p == q) return p;
	return q = find(q);
}

inline void merge(size_t p, size_t q) {
	p = find(p);
	q = find(q);
	parent[q] = p;
}

void topologicalSort(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	topologicalSort(map[idx]);
	
	topological.emplace_back(idx);
}

void getSCC(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : revMap[idx]) getSCC(v);
	merge(current, idx);
}

vector<bool> isRoot;
vector<size_t> nodeSize;
vector<unordered_set<size_t>> sccGraph;
unordered_map<size_t, size_t> sccMapper;

inline void SCC() {
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	fill_n(visit, n, false);
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		current = *i;
		getSCC(*i);
	}
	for (size_t i = 0; i < n; i++) {
		const size_t &sccID = find(i);
		if (sccMapper.find(sccID) == sccMapper.end()) {
			sccMapper[sccID] = sccMapper.size() - 1;
			sccGraph.emplace_back();
			
			nodeSize.emplace_back(0);
			isRoot.emplace_back(true);
		}
		
		nodeSize[sccMapper[sccID]]++;
	}
}


size_t solve(size_t node) {
	const auto &children = sccGraph[node];
	
	size_t sum = nodeSize[node];
	
	for (auto next : children) {
		sum += solve(next);
	}
	
	return sum;
}

vector<pair<size_t, size_t>> arr;
vector<vector<size_t>> dp;

size_t dpSolve(size_t w, size_t idx) {
	size_t &p = dp[w][idx];
	if (p != k + 1) return p;
	p = dpSolve(w, idx - 1);
	size_t ret;
	
	for (size_t i = arr[idx].first; i <= arr[idx].second && i <= w; i++) {
		ret = dpSolve(w - i, idx - 1) + i;
		if (ret <= w) p = max(p, ret);
	}
	
	return p;
}

int main() {
	scanf("%zu%zu", &n, &k);
	
	revMap.resize(n);
	
	for (size_t i = 0; i < n; i++) {
		parent[i] = i;
		
		size_t &a = map[i];
		scanf("%zu", &a);
		a--;
		revMap[a].emplace_back(i);
	}
	
	SCC();
	
	for (size_t i = 0; i < n; i++) {
		const size_t &sccID = parent[i];
		for (auto next : revMap[i]) {
			if (parent[next] != sccID) {
				sccGraph[sccMapper[sccID]].emplace(sccMapper[parent[next]]);
				
				isRoot[sccMapper[parent[next]]] = false;
			}
		}
	}
	
	for (size_t i = 0; i < isRoot.size(); i++) {
		if (isRoot[i] && nodeSize[i] <= k) {
			arr.emplace_back(nodeSize[i], solve(i));
		}
	}
	
	if (arr.empty()) puts("0");
	else {
		dp.resize(k + 1, vector<size_t>(arr.size(), k + 1));
		fill(dp[0].begin(), dp[0].end(), 0);
		for (size_t i = 0; i <= k && i < arr[0].first; i++) dp[i][0] = 0;
		for (size_t i = arr[0].first; i <= k && i <= arr[0].second; i++) dp[i][0] = i;
		for (size_t i = arr[0].second; i <= k; i++) dp[i][0] = arr[0].second;
		
		printf("%zu", dpSolve(k, arr.size() - 1));
	}
}