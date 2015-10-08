#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<int> arr;

	while (~scanf("%d", &n)) {
		int t;

		arr.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);

			auto iter = lower_bound(arr.begin(), arr.end(), t);
			if (iter == arr.end()) arr.push_back(t);
			else *iter = t;
		}

		printf("%d\n", arr.size());
	}
}