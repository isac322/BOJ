#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

set<char> ans[26];
vector<size_t> map[26], revMap[26], topological;
bool visit[26], check[26];
size_t n, current, sccId[26];

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
	ans[current].emplace(idx + 'A');
}

inline void SCC() {
	current = 0;
	topological.clear();
	fill_n(visit, 26, false);
	
	for (size_t i = 0; i < 26; i++) if (check[i]) topologicalSort(i);
	
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		if (visit[*i]) {
			makeSCC(*i);
			current++;
		}
	}
}

int main() {
	char ch[5], c;
	while (true) {
		scanf("%zu%*c", &n);
		if (!n) break;
		
		fill_n(check, 26, false);
		for (size_t i = 0; i < 26; i++) ans[i].clear(), map[i].clear(), revMap[i].clear();
		
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < 5; j++) {
				scanf("%c%*c", ch + j);
				ch[j] -= 'A';
				check[ch[j]] = true;
			}
			scanf("%c%*c", &c);
			c -= 'A';
			for (char v : ch) {
				map[v].emplace_back(c);
				revMap[c].emplace_back(v);
			}
		}
		SCC();
		
		sort(ans, ans + current);
		for (size_t i = 0; i < current; i++) {
			for (char v : ans[i]) printf("%c ", v);
			puts("");
		}
		puts("");
	}
}