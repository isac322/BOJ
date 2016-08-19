#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	vector< pair<Node *, int> >in;
	int time = 0, edges = 0;
	vector<Node *> criticals;
	bool tv = false, ev = false;
} cities[10000], *start, *last;

int calc_delay(Node * city) {
	vector<Node *> &critical = city->criticals;
	int &t = city->time;

	if (city->tv) return t;
	city->tv = true;

	for (const auto &c : city->in) {
		const int &p = calc_delay(c.first) + c.second;

		if (p > t) {
			t = p;
			critical.clear();
			critical.push_back(c.first);
		}
		else if (p == t) critical.push_back(c.first);
	}

	return t;
}

int calc_edges(Node * const city) {
	int &p = city->edges;

	if (city->ev) return 0;
	city->ev = true;

	p = city->criticals.size();
	for (auto node : city->criticals) {
		p += calc_edges(node);
	}

	return p;
}

int main() {
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);

	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;

		cities[b].in.emplace_back(cities + a, c);
	}
	scanf("%d %d", &a, &b);
	start = cities + a - 1;
	start->edges = start->time = 0;
	start->tv = start->ev = true;
	last = cities + b - 1;

	printf("%d\n", calc_delay(last));
	printf("%d", calc_edges(last));
}