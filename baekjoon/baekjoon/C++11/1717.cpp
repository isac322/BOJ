#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> *group;
vector<int>::iterator iter;
int table[1000001];

int main() {
	int n, m, i, j, a, b, c,len;
	scanf("%d %d", &n, &m);
	group = new vector<int>[n + 1]();
	for (i = 0; i <= n; i++) {
		group[i].push_back(i);
		table[i] = i;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) {
			if (table[b] == table[c]) puts("YES");
			else puts("NO");
		} else if (table[b] != table[c]) {
			int src = table[c];
			int dest = table[b];
			len = group[src].size();

			for (j = 0; j < len; j++) {
				int t = group[src][j];
				table[t] = dest;
				group[dest].push_back(t);
			}
			group[src].clear();
            group[src].shrink_to_fit();
		}
	}
}