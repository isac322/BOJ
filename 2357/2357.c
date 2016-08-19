#include <stdio.h>

int tree[400001], tree2[400001];
int arr[100000];
int n, k;

int init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) >> 1;

	int p = init(left, mid, node * 2);
	int q = init(mid + 1, right, node * 2 + 1);

	return tree[node] = p < q ? p : q;
}

int init2(int left, int right, int node) {
	if (left == right) return tree2[node] = arr[left];

	int mid = (left + right) >> 1;

	int p = init2(left, mid, node * 2);
	int q = init2(mid + 1, right, node * 2 + 1);

	return tree2[node] = p > q ? p : q;
}


int a, b;

int query(int node, int left, int right) {
	if (a > right || b < left) return 1987654321;

	if (a <= left && b >= right) return tree[node];

	int mid = (left + right) >> 1;
	int p = query(node * 2, left, mid);
	int q = query(node * 2 + 1, mid + 1, right);

	return p < q ? p : q;
}

int query2(int node, int left, int right) {
	if (a > right || b < left) return 0;

	if (a <= left && b >= right) return tree2[node];

	int mid = (left + right) >> 1;
	int p = query2(node * 2, left, mid);
	int q = query2(node * 2 + 1, mid + 1, right);

	return p > q ? p : q;
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	init(0, n - 1, 1);
	init2(0, n - 1, 1);

	for (int i = 0; i < k; i++) {
		scanf("%d%d", &a, &b);

		a--, b--;
		printf("%d %d\n", query(1, 0, n - 1), query2(1, 0, n - 1));
	}
}