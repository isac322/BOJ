#include <stdio.h>

int main() {
	int n, k;
	for (scanf("%d %d", &n, &k); n&&k; scanf("%d %d", &n, &k)) {
		int node[1000] = { 0 }, parent[1000] = { 0 };
		int nodeK = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d", node + i);
			if (node[i] == k) nodeK = i;
		}

		int current = parent[0] = -1;
		for (int i = 1; i < n; i++) {
			if (node[i] != node[i - 1] + 1) 	current++;
			parent[i] = current;
		}

		int cousins = 0;
		if (parent[nodeK] != -1) for (int i = 1; i < n; i++) if (parent[parent[i]] == parent[parent[nodeK]] && parent[i] != parent[nodeK]) cousins++;
		printf("%d\n", cousins);
	}
}