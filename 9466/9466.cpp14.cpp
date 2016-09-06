#include <cstdio>
#include <algorithm>

using namespace std;

int map[100000];
int t, n, cnt;
bool inStack[100000], visit[100000];
int root;

bool dfs(int here) {
	if (visit[here]) return false;
	inStack[here] = true;

	int next = map[here];
	bool ret;
	if (visit[next]) {
		cnt++;
		ret = false;
	}
	else if (inStack[next]) {
		root = next;
		ret = next != here;
	}
	else if (dfs(next)) {
		ret = root != here;
	}
	else {
		cnt++;
		ret = false;
	}

	inStack[here] = false;
	visit[here] = true;

	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", map + i);
			map[i]--;
		}
		fill_n(inStack, n, false);
		fill_n(visit, n, false);
		cnt = 0;

		for (int i = 0; i < n; i++) {
			root = n;
			dfs(i);
		}
		printf("%d\n", cnt);
	}
}