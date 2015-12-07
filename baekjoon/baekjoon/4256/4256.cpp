#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

short arr[1000], match[1001];

void solve(short root, short length, short start) {
	short &node = arr[root];
	short left = match[node] - start;

	if (left != 0) solve(root + 1, left, start);
	if (length != match[node] - start + 1) {
		solve(root + left + 1, length - left - 1, match[node] + 1);
	}

	printf("%d ", node);
}

int main() {
	int c;
	scanf("%d", &c);

	while (c--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) scanf("%hd", &arr[i]);
		for (int i = 0; i < n; i++) {
			short t;
			scanf("%hd", &t);
			match[t] = i;
		}

		solve(0, n, 0);
		puts("");
	}
}