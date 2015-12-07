#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int tree[400001];
int arr[100000];
int n, k;

int init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) >> 1;

	return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}


int a, b;

int query(int node, int left, int right) {
	if (a > right || b < left) return 1987654321;

	//if (left == right) return tree[node];
	if (a <= left && b >= right) return tree[node];

	int mid = (left + right) >> 1;
	return min(query(node * 2, left, mid), query(node * 2 + 1, mid + 1, right));
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	init(0, n - 1, 1);

	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a, &b);

		a--, b--;
		printf("%d\n", query(1, 0, n - 1));
	}
}