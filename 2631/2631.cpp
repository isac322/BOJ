#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), t);
		if (iter == arr.end()) arr.push_back(t);
		else *iter = t;
	}

	printf("%d", n - arr.size());
}