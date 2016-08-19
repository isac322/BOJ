#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char cnt[10001];
short tree[10001][2];
short root;
vector< pair<int, int> > levels;
int level = 0;

int solve(int level, int start, int root) {
	::level = max(level, ::level);

	const short &left = tree[root][0];
	const short &right = tree[root][1];

	int &low = levels[level].first;
	int &high = levels[level].second;

	int size = 1;
	if (left != -1) {
		int val = solve(level + 1, start, left);
		size += val;
	}

	low = min(low, start + size);
	high = max(high, start + size);

	if (right != -1) {
		int val = solve(level + 1, start + size, right);
		size += val;
	}

	return size;
}

int main() {
	int n, parent;
	scanf("%d", &n);
	levels.resize(n, make_pair(0x7fffffff, 0));

	for (int i = 0; i < n; i++) {
		scanf("%d", &parent);

		short &left = tree[parent][0];
		short &right = tree[parent][1];

		scanf("%hd %hd", &left, &right);

		cnt[left]++;
		cnt[right]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			root = i;
			break;
		}
	}

	solve(0, 0, root);

	int val = 0, max = 0;
	for (int i = 0; i <= level; i++) {
		int t = levels[i].second - levels[i].first + 1;
		if (t > val) {
			max = i;
			val = t;
		}
	}

	printf("%d %d", max + 1, val);
}