#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<int, int>> arr;
	int n, t, a, s;
	scanf("%d", &t);
	while (t--) {
		s = 0;
		arr.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			arr.emplace_back(a, i);
			s += a;
		}
		sort(arr.begin(), arr.end());
		if (arr[arr.size() - 1].first == arr[arr.size() - 2].first) puts("no winner");
		else printf("%sority winner %d\n", arr.back().first * 2 > s ? "maj" : "min", arr.back().second + 1);
	}
}