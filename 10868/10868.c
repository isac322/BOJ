#include <stdio.h>

int tree[400001];
int arr[100000];
int n, k;

int init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) >> 1;

	int a = init(left, mid, node * 2);
	int b = init(mid + 1, right, node * 2 + 1);

	return tree[node] = a < b ? a : b;
}


int a, b;

int query(int node, int left, int right) {
	if (a > right || b < left) return 1987654321;

	if (a <= left && b >= right) return tree[node];

	int mid = (left + right) >> 1;
	int a = query(node * 2, left, mid);
	int b = query(node * 2 + 1, mid + 1, right);

	return a < b ? a : b;
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