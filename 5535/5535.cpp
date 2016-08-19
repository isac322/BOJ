#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Clothes {
	char a, b, c;
}clothes[200];

int d, n;
char days[200];
int dp[200][101];

int solve(short day, short prev) {
	if (day == d) return 0;

	int &ret = dp[day][prev];

	if (ret != -1) return ret;

	ret = 0;
	const char &templ = days[day];
	for (int i = 0; i < n; i++) {
		const Clothes &t = clothes[i];

		if (t.a <= templ && t.b >= templ) {
			ret = max(ret, solve(day + 1, t.c) + abs(prev - t.c));
		}
	}

	return ret;
}

int main() {
	scanf("%d %d", &d, &n);

	for (int i = 0; i < d; i++) {
		fill_n(dp[i], 101, -1);
		scanf("%hhd", days + i);
	}
	for (int i = 0; i < n; i++) scanf("%hhd %hhd %hhd", &clothes[i].a, &clothes[i].b, &clothes[i].c);

	int re = 0;
	for (int i = 0; i < n; i++) {
		const Clothes &t = clothes[i];

		if (t.a <= days[0] && t.b >= days[0]) re = max(re, solve(1, t.c));
	}

	printf("%d", re);
}