#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, tree[262145], a, b;
short arr[100000];

int init(int node, int start, int end) {
	int &p = tree[node];

	if (start == end) return p = arr[start - 1];

    int half = (start + end) >> 1, no = node << 1;
	return p = init(no, start, half) + init(no + 1, half + 1, end);
}

int get(int node, int left, int right) {
	if (left > b || right < a) return 0;
	else if (a <= left && right <= b) return tree[node];
	else {
		int half = (left + right) >> 1, no = node << 1;
		return get(no, left, half) + get(no + 1, half + 1, right);
    }
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