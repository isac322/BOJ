#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

short n, t;
vector<short> arr;
int main() {
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) {
		scanf("%hd", &t);

		auto a = lower_bound(arr.begin(), arr.end(), t);
		if (a == arr.end()) arr.push_back(t);
		else *a = t;
	}

	printf("%zd", arr.size());
}