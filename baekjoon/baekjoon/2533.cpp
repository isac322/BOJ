#include <stdio.h>
#include <vector>
using namespace std;

vector<int> tree[1000000];
int dp[1000000][2] = { 0 };
bool visit[1000000][2] = { false };

int calc(int index, int sel, int paren) {
	int i = 0, len = tree[index].size(), a, b, sum = 0, j;
	if (sel == 0) {
		for (; i < len; i++) {
			j = tree[index][i];
			if (j != paren) {
				a = visit[j][1] ? dp[j][1] : calc(j, 1, index);
				sum += a;
			}
		}
	} else {
		for (; i < len; i++) {
			j = tree[index][i];
			if (tree[index][i] != paren) {
				a = visit[j][1] ? dp[j][1] : calc(j, 1, index);
				b = visit[j][0] ? dp[j][0] : calc(j, 0, index);
				sum += a > b ? b : a;
			}
		}
		sum++;
	}
	visit[index][sel] = true;
	return dp[index][sel] = sum;
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