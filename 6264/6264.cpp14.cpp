#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

map<string, size_t> wordMapper;
vector<string> words;
unordered_set<size_t> selectedWord;

vector<vector<size_t>> graph, revGraph;
vector<size_t> sccId, topological, sccSize;
vector<bool> visit;
size_t n, current;

void topologicalSort(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto v : graph[idx]) topologicalSort(v);
	
	topological.emplace_back(idx);
}

void makeSCC(size_t idx) {
	if (!visit[idx]) return;
	visit[idx] = false;
	
	for (auto v : revGraph[idx]) makeSCC(v);
	sccId[idx] = current;
	sccSize[current]++;
}

void SCC() {
	topological.clear();
	sccId.resize(n);
	visit.resize(n);
	
	fill(visit.begin(), visit.end(), false);
	for (size_t i = 0; i < n; i++) topologicalSort(i);
	
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		current = *i;
		makeSCC(*i);
		if (sccSize[*i] == 1 && !revGraph[*i].empty()) sccSize[*i] = 0;
	}
}

inline size_t insertWord(const string &str) {
	const auto &ret = wordMapper.find(str);
	if (ret == wordMapper.end()) {
		graph.emplace_back();
		revGraph.emplace_back();
		
		wordMapper[str] = words.size();
		words.emplace_back(str);
		return words.size() - 1;
	}
	else return ret->second;
}

size_t sum = 0;

void reverseDFS(size_t idx) {
	if (visit[idx]) return;
	visit[idx] = true;
	
	for (auto next : revGraph[idx]) {
		reverseDFS(next);
	}
	
	selectedWord.emplace(sccId[idx]);
	sum++;
}

int main() {
	int c = 0;
	size_t root, here;
	string s, a;
	while (true) {
		scanf("%zu", &n);
		if (!n) break;
		getchar();
		
		sccSize.resize(n);
		fill(sccSize.begin(), sccSize.end(), 0);
		
		words.clear();
		wordMapper.clear();
		graph.clear();
		revGraph.clear();
		selectedWord.clear();
		
		for (size_t i = 0; i < n; i++) {
			s.clear();
			while ((c = getchar()) != 32 && c != 10) s.push_back(char(c));
			root = insertWord(s);
			if (c == 10) continue;
			
			s.clear();
			while ((c = getchar()) != 10) {
				if (c == 32) {
					if (s.empty()) continue;
					here = insertWord(s);
					s.clear();
					
					graph[here].emplace_back(root);
					revGraph[root].emplace_back(here);
				}
				else s.push_back(char(c));
			}
			if (!s.empty()) {
				here = insertWord(s);
				
				graph[here].emplace_back(root);
				revGraph[root].emplace_back(here);
			}
		}
		
		SCC();
		
		sum = 0;
		for (size_t i = 0; i < n; i++) if (sccSize[i] > 0) reverseDFS(i);
		
		printf("%zu\n", sum);
		for (auto &v : wordMapper) {
			if (selectedWord.find(sccId[v.second]) != selectedWord.end()) printf("%s ", v.first.c_str());
		}
		if (sum) puts("");
	}
}