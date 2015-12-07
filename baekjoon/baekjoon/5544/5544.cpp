#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n, team[100] = {0};

int main() {
	scanf("%d", &n);

	int t = n * (n - 1) >> 1;
	for (int i = 0; i < t; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a--, b--;
		if (c > d) team[a] += 3;
		else if (c < d) team[b] += 3;
		else team[a]++, team[b]++;
	}

	vector<int> arr(team, team + n);
	sort(arr.begin(), arr.end(), greater<int>());

	for (int i = 0; i < n; i++) {
		printf("%ld\n",  distance(arr.begin(), find(arr.begin(), arr.end(), team[i])) + 1);
	}
}