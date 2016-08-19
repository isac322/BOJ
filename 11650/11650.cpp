#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	pair<int, int> arr[100000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) printf("%d %d\n", arr[i].first, arr[i].second);
}