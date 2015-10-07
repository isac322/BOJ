#include <cstdio>
#include <algorithm>

using namespace std;

struct Nation {
	int num;
	int gold, silver, bronze;
	int rank;

	inline bool operator<(const Nation &v) const {
		if (gold == v.gold) {
			if (silver == v.silver) {
				if (bronze == v.bronze) {
					return this < &v;
				}
				else return bronze > v.bronze;
			}
			else return silver > v.silver;
		}
		else return gold > v.gold;
	}

	inline bool operator==(const Nation &v) const {
		return gold == v.gold && silver == v.silver && bronze == v.bronze;
	}
};

Nation nations[1000];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		Nation &p = nations[i];
		scanf("%d %d %d %d", &p.num, &p.gold, &p.silver, &p.bronze);
	}

	sort(nations, nations + n);

	nations[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (nations[i] == nations[i - 1]) nations[i].rank = nations[i - 1].rank;
		else nations[i].rank = i + 1;
	}

	for (int i = 0; i < n; i++) {
		if (nations[i].num == k) printf("%d", nations[i].rank);
	}
}