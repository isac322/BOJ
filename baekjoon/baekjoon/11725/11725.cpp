#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[100001];
int n, a, b;
int parent[100001] = { 0, -1 };

void solve(int node) {
	for (vector<int>::iterator i = tree[node].begin(); i != tree[node].end(); i++) {
		if (!parent[*i]) {
			parent[*i] = node;
			solve(*i);
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	solve(1);

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
}