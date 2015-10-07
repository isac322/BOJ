#include <cstdio>
#include <vector>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;

typedef unordered_map<int, short>::iterator ITER;

unordered_map<int, short> map;

int arr[1000], n, c;

struct SORTER {
	inline bool operator()(const ITER &l, const ITER &r) const {
		if (l->second == r->second) return find(arr, arr + n, l->first) < find(arr, arr + n, r->first);
		else return l->second > r->second;
	}
};

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		int &p = arr[i];
		scanf("%d", &p);

		map[p]++;
	}

	vector<ITER> iters;
	for (ITER i = map.begin(); i != map.end(); i++) iters.push_back(i);

	sort(iters.begin(), iters.end(), SORTER());
	for (int i = 0; i < iters.size(); i++) {
		const short &cnt = iters[i]->second;
		const int &num = iters[i]->first;
		for (int j = 0; j < cnt; j++) printf("%d ", num);
	}
}