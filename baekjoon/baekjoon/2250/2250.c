#include <stdio.h>
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

char cnt[10001];
short tree[10001][2];
short root;
int levels[10000][2];
int max_level = 0;

int solve(int level, int start, int root) {
	max_level = max(level, max_level);

	const short left = tree[root][0];
	const short right = tree[root][1];

	int size = 1;
	if (left != -1) {
		int val = solve(level + 1, start, left);
		size += val;
	}

	levels[level][0] = min(levels[level][0], start + size);
	levels[level][1] = max(levels[level][1], start + size);

	if (right != -1) {
		int val = solve(level + 1, start + size, right);
		size += val;
	}

	return size;
}

int main() {
	int n, parent;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		levels[i][0] = 0x7fffffff;
		levels[i][1] = 0;
		scanf("%d", &parent);

		short *left = tree[parent];
		short *right = tree[parent] + 1;

		scanf("%hd %hd", left, right);

		cnt[*left]++;
		cnt[*right]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			root = i;
			break;
		}
	}

	solve(0, 0, root);

	int val = 0, max = 0;
	for (int i = 0; i <= max_level; i++) {
		int t = levels[i][1] - levels[i][0] + 1;
		if (t > val) {
			max = i;
			val = t;
		}
	}

	printf("%d %d", max + 1, val);
}