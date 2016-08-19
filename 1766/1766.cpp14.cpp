#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent[32001];
int children[32001], n, m;

int main() {
	int a, b;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		parent[a].emplace_back(b);
		children[b]++;
	}
	priority_queue<int> que;
	for (int i = 1; i <= n; i++) if (children[i] == 0) que.emplace(-i);
	for (int i = 0; i < n; i++) {
		int leaf = -que.top();
		que.pop();
		printf("%d ", leaf);
		for (int p : parent[leaf]) if (--children[p] == 0) que.emplace(-p);
	}
}