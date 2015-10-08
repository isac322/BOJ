#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, short> ISP;

int max_cost[100000];
vector< ISP > cost[100000];

int calc(const int root, const int parent) {
	vector< ISP > &children = cost[root];
	const size_t &len = children.size();
	int &ret = max_cost[root];

	for (size_t i = 0; i < len; i++) {
		int &child = children[i].first;

		if (child == parent) child = -1;
		else ret = max(ret, calc(child, root) + children[i].second);
	}

	return ret;
}

int solve(const int root) {
	const vector< ISP > &children = cost[root];
	const size_t &len = children.size();
	int ret = 0;

	int a = 0, b = 0;
	for (size_t i = 0; i < len; i++) {
		const int &child = children[i].first;

		if (child == -1) continue;
		ret = max(ret, solve(child));

		int t = max_cost[child] + children[i].second;
		if (a < t) {
			a = t;

			if (a > b) swap(a, b);
		}
	}

	return max(a + b, ret);
}

int main() {
	int n;
	scanf("%d", &n);

	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		vector< ISP > &t = cost[a - 1];

		while (true) {
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &c);
			t.push_back(make_pair(b - 1, c));
		}
	}

	calc(0, -1);

	printf("%d\n", solve(0));
}