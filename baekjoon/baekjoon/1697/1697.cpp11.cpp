#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100001];

int main() {
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	if (n > k) printf("%d", n - k);
	else {
		queue<int> que;
		que.emplace(n);

		for (;; cnt++) {
			size_t len = que.size();

			for (size_t i = 0; i < len; i++) {
				int t = que.front();
				que.pop();

				if (t < 0 || t > 100000 || visited[t]) continue;
				else if (t == k) {
					printf("%d", cnt);
					return 0;
				}
				visited[t] = true;
				que.emplace(t + 1);
				que.emplace(t - 1);
				que.emplace(t << 1);
			}
		}
	}
}