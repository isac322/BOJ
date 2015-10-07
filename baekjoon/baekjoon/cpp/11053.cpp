#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

short n, t;
vector<short> arr;
int main() {
	scanf("%hd", &n);
	for (int i = 0; i < n; i++) {
		scanf("%hd", &t);

		vector<short>::iterator a = lower_bound(arr.begin(), arr.end(), t);
		if (a == arr.end()) arr.push_back(t);
		else *a = t;
	}

	printf("%d", arr.size());
}