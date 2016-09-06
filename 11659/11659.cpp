#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, tree[262145], a, b;
short arr[100000];

int init(int node, int start, int end) {
	int &p = tree[node];

	if (start == end) return p = arr[start - 1];

	return p = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

int get(int node, int left, int right) {
	if (left > b || right < a) return 0;
	else if (a <= left && right <= b) return tree[node];
	else return get(node * 2, left, (left + right) / 2) + get(node * 2 + 1, (left + right) / 2 + 1, right);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%hd", arr + i);
	init(1, 1, n);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", get(1, 1, n));
	}
}