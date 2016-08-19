#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	short n, arr[1000];
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) scanf("%hd", arr + i);
	
	vector<short> LDS;
	vector<short>::iterator iter;
	for (short i = n - 1; i >= 0; i--) {
		iter = lower_bound(LDS.begin(), LDS.end(), arr[i]);
		if (iter == LDS.end()) LDS.push_back(arr[i]);
		else *iter = arr[i];
	}
	printf("%d", LDS.size());
}