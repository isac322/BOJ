#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[100001];
	scanf("%d", &n);
	
	scanf("%d", arr);
	int ret = arr[0];
	int t;
	for (int i = 1; i < n; i++) {
		scanf("%d", &t);

		arr[i] = arr[i - 1] + t;

		ret = max(ret,  arr[i]);
		for (int j = 0; j < i; j++) ret = max(ret, arr[i] - arr[j]);
	}

	printf("%d", ret);
}