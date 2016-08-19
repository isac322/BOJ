#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, arr[10001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	
	queue<int> que;
	size_t ans = 0;
	
	for (int i = 0; i < n; i++) {
		if (!que.empty() && que.front() + 5 <= arr[i]) {
			ans = max(ans, que.size());
			while (!que.empty() && que.front() + 5 <= arr[i]) que.pop();
		}
		
		que.emplace(arr[i]);
	}
	ans = max(ans, que.size());
	
	printf("%zd", ans > 5 ? 0 : 5 - ans);
}