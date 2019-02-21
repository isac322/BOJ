#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

vector<set<int>> SCCgraph;
vector<bool> SCCrest, visit, SCCdp;

vector<vector<int> > adj;

vector<int> sccId;
vector<int> discovered/*scc atm*/, finished/*scc dfs dp*/;

int *atm;

stack<int> st;

int sccCounter, vertexCounter;


int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int there : adj[here]) {
		if (discovered[there] == -1) ret = min(ret, scc(there));
		else if (discovered[there] < discovered[here] && sccId[there] == -1) ret = min(ret, discovered[there]);
	}

	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
	}
	finished[here] = 1;
	return ret;
}

inline void tarjanSCC() {
	sccId.resize(adj.size(), -1);
	discovered.resize(adj.size(), -1);

	finished.resize(adj.size(), 0);
	for (int i = 0; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
}

bool atmDFS(int id) {
	if (visit[id]) return SCCdp[id];
	visit[id] = true;

	bool check = SCCrest[id];
	int num = 0;

	for (auto v : SCCgraph[id]) {
		check |= atmDFS(v);
		num = max(num, finished[v]);
	}

	if (!check) finished[id] = 0;
	else finished[id] = num + discovered[id];

	return SCCdp[id] = check;
}

int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	atm = new int[n];
	adj.resize(n);
	while (m--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].emplace_back(b);
	}
	for (int i = 0; i < n; i++) scanf("%d", &atm[i]);
	tarjanSCC();

	SCCgraph.resize(sccCounter);
	discovered.resize(sccCounter);
	fill(discovered.begin(), discovered.end(), 0);

	for (int i = 0; i < n; i++) {
		auto &vec = SCCgraph[sccId[i]];
		discovered[sccId[i]] += atm[i];
		for (auto v : adj[i]) {
			if (sccId[i] != sccId[v]) vec.emplace(sccId[v]);
		}
	}

	delete atm;

	int s, p;
	scanf("%d%d", &s, &p);
	s--;
	SCCrest.resize(sccCounter, false);
	visit.resize(sccCounter, false);
	SCCdp.resize(sccCounter, false);

	for (int i = 0; i < p; i++) {
		scanf("%d", &a);
		SCCrest[sccId[--a]] = true;
	}

	atmDFS(sccId[s]);
	printf("%d", finished[sccId[s]]);
}