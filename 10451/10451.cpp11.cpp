#include <cstdio>
#include <algorithm>

using namespace std;

int parent[1000];

int find(int p) {
	if (p == parent[p]) return p;
	return parent[p] = find(parent[p]);
}

bool merge(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return false;
	parent[q] = p;
	return true;
}

int main() {
	int t, n, a;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) parent[i] = i;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			merge(i, a - 1);
		}
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			find(i);
			if (merge(0, i)) cnt++;
		}
		printf("%d\n", cnt);
	}
}