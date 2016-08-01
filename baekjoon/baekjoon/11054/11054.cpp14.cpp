#include <cstdio>
#include <algorithm>

using namespace std;

short n, dp1[1000], dp2[1000], arr[1000];
int m = 0;

int main() {
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) scanf("%hd", arr + i);
	dp1[0] = dp2[n - 1] = 1;
	for (short i = 1; i < n; i++) {
		for (short j = i - 1; j >= 0; j--) if (arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j]);
		dp1[i]++;
	}
	for (short i = n - 2; i >= 0; i--) {
		for (short j = i + 1; j < n; j++) if (arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j]);
		dp2[i]++;
	}
	for (short i = 0; i < n; i++) m = max(m, dp1[i] + dp2[i]);
	printf("%d", m - 1);
}