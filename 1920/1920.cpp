#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int t, n;
	vector<int> arr;
	vector<int>::iterator iter;
	scanf("%d", &t);
	arr.resize(t);
	for (int i = 0; i < t; i++) scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		iter = find(arr.begin(), arr.end(), n);
		if (iter == arr.end()) puts("0");
		else puts("1");
	}
}