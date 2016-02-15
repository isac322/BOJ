#include <cstdio>
#include <vector>

using namespace std;

template <typename T, typename N = T>
struct SegmentTree {
	vector<T> tree;
	size_t size, range, left, right;

	T query(const size_t begin, const size_t end, const size_t node) {
		if (left > end || right < begin) return 0;
		else if (left <= begin && end <= right) return tree[node];
		else {
			const size_t mid = (begin + end) >> 1;
			return query(begin, mid, node * 2) + query(mid + 1, end, node * 2 + 1);
		}
	}

	T query(const size_t left, const size_t right) {
		this->left = left;
		this->right = right;

		return query(0, range - 1, 1);
	}

	T init(const vector<N> &arr, const size_t left, const size_t right, const size_t node) {
		if (left == right) return tree[node] = arr[left];
		else {
			const size_t mid = (left + right) >> 1;
			return tree[node] = init(arr, left, mid, node * 2) + init(arr, mid + 1, right, node * 2 + 1);
		}
	}

	SegmentTree(const vector<N> &arr) {
		size_t cnt = 0;

		range = arr.size();
		for (size_t s = range; s != 0; s >>= 1) cnt++;
		if (range << 1 != size_t(1) << cnt) cnt++;

		size = (1 << cnt) + 1;
		tree.resize(size);

		init(arr, 0, range - 1, 1);
	}
};

int main() {
	int n, m, a, b;
	scanf("%d", &n);
	vector<short> arr(n);
	for (int i = 0; i < n; i++) scanf("%hd", &arr[i]);
	SegmentTree<long long, short> tree(arr);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%lld\n", tree.query(a - 1, b - 1));
	}
}