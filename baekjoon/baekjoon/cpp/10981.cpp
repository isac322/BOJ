#include <cstdio>
#include <algorithm>
#include <vector>
#include <tr1/unordered_map>
#include <string>

using namespace std;
using namespace std::tr1;

struct Team {
	char univ[31], name[31];
	int solve, penalty;

	inline bool operator<(const Team &val) const {
		if (solve == val.solve) return penalty < val.penalty;
		else return solve > val.solve;
	}
}team[100000];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	unordered_map<string, Team> ma;
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d %d", &team[i].univ, &team[i].name, &team[i].solve, &team[i].penalty);

		Team &p = ma[string(team[i].univ)];
		if (team[i] < p) p = team[i];
	}

	vector<Team> result;
	for (unordered_map<string, Team>::iterator i = ma.begin(); i != ma.end(); i++) {
		result.push_back(i->second);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < k; i++) {
		printf("%s\n", result[i].name);
	}
}