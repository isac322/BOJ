#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;

int temp[500][500];
pair<short, short> arr[500];
int n, dp[500][500];

int solve(int s, int e) {
	int &p = dp[s][e];
	if (p) return p;
	if (s == e) return p = 0;

	p = numeric_limits<int>::max();
	for (int i = s; i < e; i++) {
		p = min(p, solve(s, i) + solve(i + 1, e) + temp[s][i] * arr[e].second);
	}

	return p;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%hd %hd", &arr[i].first, &arr[i].second);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) temp[i][j] = arr[i].first*arr[j].second;
	printf("%d", solve(0, n - 1));
}