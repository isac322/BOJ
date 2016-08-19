#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> possible[5001];
long long sum1[5001];

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		int n, a, b, s;
		long long cnt = 0;
		scanf("%d %d", &s, &n);

		for (int i = 1; i < 5001; i++) possible[i].clear();

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			int t = a;
			for (int i = 1; i <= b; i++) {
				possible[i].emplace_back(t);
				t += a;
			}
		}

		for (int i = 1; i < 5001; i++) {
			if (!possible[i].empty()) {
				fill_n(sum1, s + 1, 0);
				sum1[0] = 1;
				for (int t : possible[i]) {
					for (int i = s - t; i >= 0; i--) {
						if (sum1[i]) {
							sum1[i + t] += sum1[i];
						}
					}
				}

				cnt += sum1[s];
			}
		}

		printf("Case %d: %lld\n", c, cnt);
	}
}