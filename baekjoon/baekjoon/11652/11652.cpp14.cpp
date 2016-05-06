#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[1'000'001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", arr + i);
	sort(arr, arr + n);

	int cnt = 0, m = 0;
	long long num, c = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] == c) cnt++;
		else {
			if (cnt > m) {
				num = c;
				m = cnt;
			}
			c = arr[i];
			cnt = 1;
		}
	}
	if (m < cnt) num = arr[n - 1];
	printf("%lld", num);
}