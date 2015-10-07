#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Node {
	int order;

	vector<int> in;

	void clear() {
		order = -1;
		in.clear();
	}
};

int n;
Node nodes[1001];

int solve(int num) {
	int &p = nodes[num].order;
	if (p != -1) return p;

	const vector<int> &in = nodes[num].in;
	const int &len = in.size();

	if (len == 0) return p = 1;
	else if (len == 1) return p = solve(in[0]);

	vector<int> orders(len);
	for (int i = 0; i < len; i++) {
		orders[i] = solve(in[i]);
	}
	sort(orders.begin(), orders.end(), greater<int>());

	if (orders[0] == orders[1]) return p = orders[0] + 1;
	else return p = orders[0];
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int q, p;
		scanf("%d %d %d", &q, &n, &p);

		for (int i = 1; i <= n; i++) nodes[i].clear();

		for (int i = 0; i < p; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			nodes[b].in.push_back(a);
		}

		printf("%d %d\n", q, solve(n));
	}
}