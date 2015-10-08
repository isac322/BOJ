#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) arr[i] = i + 1;;
	do {
		for (int i = 0; i < n; i++) printf("%d ", arr[i]);
		puts("");
	} while (next_permutation(arr.begin(), arr.end()));
}