#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, t;
	vector<int> arr;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		auto iter = lower_bound(arr.begin(), arr.end(), t);
		if (iter == arr.end()) arr.emplace_back(t);
		else *iter = t;
	}
	printf("%d", arr.size());
}