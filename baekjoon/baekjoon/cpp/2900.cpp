#include <cstdio>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;

namespace itree {
	typedef long long val_t;
	const int size = 1 << 20;

	const val_t init_value = 0;

	inline val_t sum(val_t a, val_t b) {
		return a + b;
	}

	vector<val_t> itree(size * 2 + 1);

	void init() {
		for (int i = 1; i <= size * 2; i++)
			itree[i] = init_value;
	}

	void update(int pos, val_t val) {
		pos |= size;
		itree[pos] = val;
		while (pos >>= 1)
			itree[pos] = sum(itree[pos << 1], itree[pos << 1 | 1]);
	}

	val_t getrange(int s, int e) { // [s, e]
		val_t ret = init_value;
		s |= size;
		e |= size;
		while (s <= e) {
			if (s & 1)
				ret = sum(ret, itree[s]);
			if ((e & 1) == 0)
				ret = sum(ret, itree[e]);
			s = (s + 1) >> 1;
			e = (e
				 - 1) >> 1;

		}
		return ret;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> arr(n, 0);

	tr1::unordered_map<int, int> map;
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		map[x]++;
	}
	arr[0] = k;
	for (tr1::unordered_map<int, int>::iterator i = map.begin(); i != map.end(); i++) {
		const int &num = i->first;

		for (int j = num; j < n; j += num) {
			arr[j] += i->second;
		}
	}

	for (int i = 0; i < n; i++) itree::update(i, arr[i]);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%lld\n", itree::getrange(a, b));
	}
}