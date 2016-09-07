#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<size_t>> map, revMap;
vector<size_t> parent, topological, size, dp;
vector<bool> visit;
size_t n, current;
size_t m, s, t, a, b;

size_t find(size_t p) {
	size_t &q = parent[p];
	if (p == q) return p;
	return q = find(q);
}

inline void merge(size_t p, size_t q) {
	p = find(p);
	q = find(q);
	parent[q] = p;
	if (p != q) size[p] += size[q];
}

inline void init() {
	size.resize(n, 1);
	parent.resize(n);
	for (size_t i = 0; i < n; i++) parent[i] = i;
}

void topologicalSort(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : map[idx]) topologicalSort(v);
	
	topological.emplace_back(idx);
}

void getSCC(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : revMap[idx]) getSCC(v);
	merge(current, idx);
}

inline void SCC() {
	init();
	
	visit.resize(n);
	
	fill(visit.begin(), visit.end(), false);
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	fill(visit.begin(), visit.end(), false);
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		current = *i;
		getSCC(*i);
	}
	for (size_t i = 0; i < n; i++) find(i);
}

void solve2(size_t node) {
	size_t sccId = parent[node];
	if (!visit[sccId]) return;
	visit[sccId] = false;
	
	for (size_t i = 0; i < n; i++) {
		if (parent[i] == sccId) {
			for (auto next : revMap[i]) if (parent[next] != sccId) solve2(next);
		}
	}
}

size_t solve(size_t node) {
	size_t sccId = parent[node];
	size_t &p = dp[sccId];
	if (visit[sccId]) return p;
	else if (sccId == parent[t]) {
		visit[sccId] = true;
		return p = size[sccId];
	}
	visit[sccId] = true;
	
	for (size_t i = 0; i < n; i++) {
		if (parent[i] == sccId) {
			for (auto next : map[i]) {
				if (parent[next] != sccId) p = max(p, solve(next));
			}
		}
	}
	
	return p += size[sccId];
}

int main() {
	scanf("%zu%zu%zu%zu", &n, &m, &s, &t);
	s--, t--;
	map.resize(n);
	revMap.resize(n);
	dp.resize(n, 0);
	
	while (m--) {
		scanf("%zu%zu", &a, &b);
		a--, b--;
		map[a].emplace_back(b);
		revMap[b].emplace_back(a);
	}
	
	SCC();
	
	solve2(t);
	solve(s);
	printf("%zu", visit[parent[t]] ? solve(s) : 0);
}