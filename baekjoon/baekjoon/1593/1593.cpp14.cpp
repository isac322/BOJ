#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	const auto test = [](int c) -> int { return c >= 'a' ? c - 'a' : c - 'A' + 26; };
	int g, s, t, ans = 0, num = 0;
	short cnt[52] = {0}, check[52] = {0}, check_len = 0;

	scanf("%d %d\n", &g, &s);
	for (int i = 0; i < g; i++) cnt[test(getchar())]++;
	getchar();

	for (int i = 0; i < 52; i++) if (cnt[i] == 0) num++;

	queue<int> que;

	for (int i = 0; i < s; i++) {
		const auto &ret = test(getchar());
		que.emplace(ret);

		if (check[ret] == cnt[ret]) num--;
		else if (check[ret] == cnt[ret] - 1) num++;
		check[ret]++;

		if (check_len == g) {
			auto &f = que.front();

			if (check[f] == cnt[f]) num--;
			else if (check[f] == cnt[f] + 1) num++;

			check[f]--;
			que.pop();
		}
		else check_len++;

		if (num == 52) ans++;
	}
	printf("%d", ans);
}