#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	pair<int, int> arr[100001];

	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
		sort(arr, arr + n);

		int cnt = 1;
		int pivot = arr[0].second;
		for (int i = 1; i < n; i++) {
			if (arr[i].second < pivot) {
				cnt++;
				pivot = arr[i].second;
			}
		}

		printf("%d\n", cnt);
	}
}