#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

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

	map<string, vector<Team> > ma;
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d %d", &team[i].univ, &team[i].name, &team[i].solve, &team[i].penalty);
		ma[string(team[i].univ)].push_back(team[i]);
	}

	vector<Team> result;
	for (map<string, vector<Team> >::iterator i = ma.begin(); i != ma.end(); i++) {
		sort(i->second.begin(), i->second.end());
		result.push_back(i->second[0]);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < k; i++) {
		printf("%s\n", result[i].name);
	}
}