#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> arr[500000];
int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	int m = 0;
	for (int i = 0; i < n; i++) m = max(m, arr[i].second - i);
	printf("%d", m);
}