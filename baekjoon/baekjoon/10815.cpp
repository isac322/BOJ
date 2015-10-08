#include <stdio.h>
#include <algorithm>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

int main() {
	unordered_map<int, bool> map;

	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);

		map[t] = true;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);

		if (map[t]) printf("1 ");
		else printf("0 ");
	}
}