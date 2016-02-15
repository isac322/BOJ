#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename N = T>
struct LazySegmentTree {
	vector<T> tree;
	vector<N> lazy;
	size_t range, left, right;
	N value;

	inline void lazyUpdate(const size_t begin, const size_t end, const size_t node) {
		if (lazy[node] & 1) {
			if (begin != end) {
				tree[node] = end - begin + 1 - tree[node];
				lazy[node * 2 + 1]++;
				lazy[node * 2 + 2]++;
			}
			else tree[node]++;
		}
		lazy[node] = 0;
	}

	T _updateRange(const size_t begin, const size_t end, const size_t node) {
		lazyUpdate(begin, end, node);

		if (right < begin || end < left) {
			if (begin == end) return tree[node] & 1;
			else return tree[node];
		}
		else if (begin == end) return (++tree[node]) & 1;
		else if (left <= begin && end <= right) {
			lazy[node * 2 + 1]++;
			lazy[node * 2 + 2]++;
			return tree[node] = end - begin + 1 - tree[node];
		}
		else {
			const size_t mid = (begin + end) >> 1;
			return tree[node] = _updateRange(begin, mid, node * 2 + 1) + _updateRange(mid + 1, end, node * 2 + 2);
		}
	}

	inline void updateRange(size_t left, size_t right) {
		if (left > right) swap(left, right);
		this->left = left;
		this->right = right;

		_updateRange(0, range - 1, 0);
	}

	T query(const size_t begin, const size_t end, const size_t node) {
		lazyUpdate(begin, end, node);

		if (right < begin || end < left) return 0;
		else if (begin == end) return tree[node] & 1;
		else if (left <= begin && end <= right) return tree[node];
		else {
			const size_t mid = (begin + end) >> 1;
			return query(begin, mid, node * 2 + 1) + query(mid + 1, end, node * 2 + 2);
		}
	}

	inline T query(size_t left, size_t right) {
		if (left > right) swap(left, right);
		this->left = left;
		this->right = right;

		return query(0, range - 1, 0);
	}

	LazySegmentTree(size_t range) {
		size_t size = 1;
		this->range = range;
		for (size_t s = range; s != 0; s >>= 1) size <<= 1;
		if (range << 1 != size) size <<= 1;

		tree.resize(size, 0);
		lazy.resize(size, 0);
	}
};

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	LazySegmentTree<int> tree(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) printf("%d\n", tree.query(b - 1, c - 1));
		else tree.updateRange(b - 1, c - 1);
	}
}