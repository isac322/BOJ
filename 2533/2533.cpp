#include <stdio.h>
#include <vector>
using namespace std;

vector<int> tree[1000000];
int dp[1000000][2] = { 0 };
bool visit[1000000][2] = { false };

int calc(int index, int sel, int paren) {
	int i = 0, len = tree[index].size(), a, b, sum = 0;
	if (sel == 0) {
		for (; i < len; i++) {
			if (tree[index][i] != paren) {
				a = visit[tree[index][i]][1] ? dp[tree[index][i]][1] : calc(tree[index][i], 1, index);
				sum += a;
			}
		}
	} else {
		for (; i < len; i++) {
			if (tree[index][i] != paren) {
				a = visit[tree[index][i]][1] ? dp[tree[index][i]][1] : calc(tree[index][i], 1, index);
				b = visit[tree[index][i]][0] ? dp[tree[index][i]][0] : calc(tree[index][i], 0, index);
				sum += a > b ? b : a;
			}
		}
		sum++;
	}
	dp[index][sel] = sum;
	visit[index][sel] = true;
	return dp[index][sel];
}

int main() {
	int n, a, b, i;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}
	for (i = 0; i < n; i++) {
		if (tree[i].size() == 1) {
			dp[i][1] = 1;
			visit[i][0] = visit[i][1] = true;
		}
	}

	int c = calc(0, 0, -1), d = calc(0, 1, -1);
	printf("%d", c < d ? c : d);
}