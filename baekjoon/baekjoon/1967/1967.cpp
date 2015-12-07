#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, char> ICP;

int max_cost[10000];
vector< ICP > cost[10000];

int calc(int root) {
	const vector< ICP > &children = cost[root];
	const size_t &len = children.size();
	int &ret = max_cost[root];

	for (size_t i = 0; i < len; i++) {
		ret = max(ret, calc(children[i].first) + children[i].second);
	}

	return ret;
}

int solve(int root) {
	const vector< ICP > &children = cost[root];
	const size_t &len = children.size();
	int ret = 0;

	int a = 0, b = 0;
	for (size_t i = 0; i < len; i++) {
		const int &child = children[i].first;
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
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);

		cost[a - 1].push_back(make_pair(b - 1, c));
	}

	calc(0);

	printf("%d\n", solve(0));
}