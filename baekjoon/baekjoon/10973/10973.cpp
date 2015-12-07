#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	if (prev_permutation(arr.begin(), arr.end())) for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	else puts("-1");
}