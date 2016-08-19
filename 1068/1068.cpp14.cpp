#include <cstdio>
#include <vector>

using namespace std;

vector<int> children[50];
int n, t, p, root;

int dfs(int n) {
	int s = 0;
	if (n == t) return 0;
	else if (children[n].empty() || (children[n][0] == t && children[n].size() == 1)) return 1;
	else for (int v : children[n]) s += dfs(v);
	return s;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		if (p == -1) root = i;
		else children[p].emplace_back(i);
	}
	scanf("%d", &t);
	printf("%d", dfs(root));
}