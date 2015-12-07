#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int u, v;

struct Person {
	int num;
	bool visited;
	vector<Person *> children;
    
	int dfs() {
		visited = true;

		if (num == v) return 0;

		for (size_t i = 0; i < children.size(); i++) {
			if (!children[i]->visited) {
				const int &ret = children[i]->dfs();

				if (ret != -1) return ret + 1;
			}
		}

		return -1;
	}
}people[100];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) people[i].num = i;
	scanf("%d %d", &u, &v);
	u--, v--;
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		people[a].children.push_back(people + b);
		people[b].children.push_back(people + a);
	}

	printf("%d", people[u].dfs());
}