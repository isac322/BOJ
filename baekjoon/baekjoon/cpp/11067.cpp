#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct COMPARE {
	inline bool operator()(const pair<int, int> &val, const pair<int, int> &val2) const {
		if (val.first == val2.first) return val.second < val2.second;
		else return val.first < val2.first;
	}
};

struct COMPARE2 {
	inline bool operator()(const pair<int, int> &val, const pair<int, int> &val2) const {
		if (val.first == val2.first) return val.second > val2.second;
		else return val.first < val2.first;
	}
};

vector<pair<int, int> > arr;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		arr.resize(n);

		for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);

		sort(arr.begin(), arr.end(), COMPARE());

		if (arr[0].first != 0 || arr[0].second != 0) {
			int t = 0;
			while (t < n && arr[t].first == 0) t++;

			sort(arr.begin(), arr.begin() + t, COMPARE2());
		}

		for (int i = 0; i < n - 1; i++) {
			if (arr[i].first != arr[i + 1].first && arr[i].second != arr[i + 1].second) {
				int x = arr[i + 1].first;
				int t = i + 1;
				while (t < n && arr[t++].first == x);

				sort(arr.begin() + i + 1, arr.begin() + t, COMPARE2());
			}
		}

		int c;
		scanf("%d", &c);

		for (int i = 0; i < c; i++) {
			int r;
			scanf("%d", &r);
			r--;
			printf("%d %d\n", arr[r].first, arr[r].second);
		}
	}
	return 0;
}