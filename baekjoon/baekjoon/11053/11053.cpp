#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, t;
vector<int> arr;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);

		vector<int>::iterator a = lower_bound(arr.begin(), arr.end(), t);
		if (a == arr.end()) arr.push_back(t);
		else *a = t;
	}

	printf("%d", arr.size());
}