#include <cstdio>
#include <vector>

using namespace std;

template <typename T, typename N = T>
struct SegmentTree {
	std::vector<T> tree;
	std::vector<N> lazy;
	size_t range, left, right;
	N value;

	T _updateRange(const size_t begin, const size_t end, const size_t node) {
		tree[node] += lazy[node] * (end - begin + 1);
		if (begin != end) {
			lazy[node * 2 + 1] += lazy[node];
			lazy[node * 2 + 2] += lazy[node];
		}
		lazy[node] = 0;

		if (right < begin || end < left) return tree[node];
		else if (begin == end) return tree[node] += value;
		else if (left <= begin && end <= right) {
			lazy[node * 2 + 1] += value;
			lazy[node * 2 + 2] += value;
			return tree[node] += (end - begin + 1)*value;
		}
		else {
			const size_t mid = (begin + end) >> 1;
			return tree[node] = _updateRange(begin, mid, node * 2 + 1) + _updateRange(mid + 1, end, node * 2 + 2);
		}
	}

	void updateRange(size_t left, size_t right, const N value) {
		if (left > right) std::swap(left, right);
		this->left = left;
		this->right = right;
		this->value = value;

		_updateRange(0, range - 1, 0);
	}

	T query(const size_t begin, const size_t end, const size_t node) {
		tree[node] += lazy[node] * (end - begin + 1);
		if (begin != end) {
			lazy[node * 2 + 1] += lazy[node];
			lazy[node * 2 + 2] += lazy[node];
		}
		lazy[node] = 0;

		if (left > end || right < begin) return 0;
		else if (begin == end) return tree[node];
		else if (left <= begin && end <= right) return tree[node];
		else {
			const size_t mid = (begin + end) >> 1;
			return query(begin, mid, node * 2 + 1) + query(mid + 1, end, node * 2 + 2);
		}
	}

	T query(size_t left, size_t right) {
		if (left > right) std::swap(left, right);
		this->left = left;
		this->right = right;

		return query(0, range - 1, 0);
	}

	T init(const std::vector<N> &arr, const size_t left, const size_t right, const size_t node) {
		if (left == right) return tree[node] = arr[left];
		else {
			const size_t mid = (left + right) >> 1;
			return tree[node] = init(arr, left, mid, node * 2 + 1) + init(arr, mid + 1, right, node * 2 + 2);
		}
	}

	SegmentTree(const std::vector<N> &arr) {
		size_t cnt = 0;

		range = arr.size();
		for (size_t s = range; s != 0; s >>= 1) cnt++;
		if (range << 1 != size_t(1) << cnt) cnt++;

		tree.resize(1 << cnt);
		lazy.resize(1 << cnt);
		fill(lazy.begin(), lazy.end(), 0);

		init(arr, 0, range - 1, 0);
	}
};

int main() {
	long long n, m, a, b, c;
	scanf("%lld %lld %lld", &n, &m, &a);
	m += a;
	vector<long long> arr(n);
	for (long long i = 0; i < n; i++) scanf("%lld", &arr[i]);
	SegmentTree<long long> tree(arr);
	for (long long i = 0; i < m; i++) {
		scanf("%lld", &a);
		if (a - 1LL) {
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", tree.query(a - 1, b - 1));
		}
		else {
			scanf("%lld %lld %lld", &a, &b, &c);
			tree.updateRange(a - 1, b - 1, c);
		}
	}
}