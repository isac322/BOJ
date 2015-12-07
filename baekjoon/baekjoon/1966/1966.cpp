#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	vector<int> arr;

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		arr.resize(n);
		deque<pair<int, int> > que;

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			que.push_back(make_pair(arr[i], i));
		}

		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; ++i) {
			while (que.front().first != *arr.rbegin()) {
				que.push_back(que.front());
				que.pop_front();
			}
			arr.pop_back();

			if (que.front().second == m) {
				printf("%d\n", i + 1);
				break;
			}

			que.pop_front();
		}
	}
}