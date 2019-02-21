#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	unsigned long n, t;
	vector<unsigned long> arr;
	scanf("%lu", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lu", &t);
		auto iter = lower_bound(arr.begin(), arr.end(), t);
		if (iter == arr.end()) arr.emplace_back(t);
		else *iter = t;
	}
	printf("%lu", arr.size());
}