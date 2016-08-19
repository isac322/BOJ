#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	vector<int> arr(n);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++) {
		if (arr[i] < x) printf("%d ", arr[i]);
	}
}