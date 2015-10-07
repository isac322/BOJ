#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);

		vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), t);
		if (iter != arr.end()) *iter = t;
		else arr.push_back(t);
	}

	printf("%d", arr.size());
}