#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

int map[100000];
int t, n, cnt;
bool inStack[100000], visit[100000];

inline void dfs(int idx) {
	stack<int> s;
	s.emplace(idx);
	inStack[idx] = true;

	while (!s.empty()) {
		int here = s.top();
		int next = map[here];

		if (visit[next]) {
			inStack[here] = false;
			visit[here] = true;
			s.pop();
			cnt++;
		}
		else if (inStack[next]) {
			while (s.top() != next) {
				inStack[s.top()] = false;
				visit[s.top()] = true;
				s.pop();
			}
			visit[next] = true;
			inStack[next] = false;
			s.pop();
		}
		else {
			s.emplace(next);
			inStack[next] = true;
		}
	}
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

		for (int i = 0; i < n; i++) if (!visit[i]) dfs(i);
		printf("%d\n", cnt);
	}
}