#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> children[32000], topological;
bool visited[32000];
int n, m, a, b;

void dfsTopologicalSort(int index) {
	if (visited[index]) return;
	visited[index] = true;
	for (auto i : children[index]) dfsTopologicalSort(i);
	topological.emplace_back(index);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		children[b].emplace_back(a);
	}
	for (int i = 0; i < n; i++) dfsTopologicalSort(i);
	for (auto i : topological) printf("%d ", i + 1);
}