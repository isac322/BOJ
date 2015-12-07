#include <stdio.h>
#include <math.h>
#include <memory.h>

struct Clothes {
	char a, b, c;
}clothes[200];

int d, n;
char days[200];
int dp[200][101];

int solve(int day, int prev) {
	if (day == d) return 0;

	int *ret = &dp[day][prev];

	if (*ret != -1) return *ret;

	*ret = 0;
	const char templ = days[day];
	for (int i = 0; i < n; i++) {
		if (clothes[i].a <= templ && clothes[i].b >= templ) {
			int t = solve(day + 1, clothes[i].c) + abs(prev - clothes[i].c);
			
			if (t > *ret) *ret = t;
		}
	}

	return *ret;
}

int main() {
	scanf("%d %d", &d, &n);

	for (int i = 0; i < d; i++) {
		memset(dp[i], -1, 404);
		scanf("%hhd", days + i);
	}
	for (int i = 0; i < n; i++) scanf("%hhd %hhd %hhd", &clothes[i].a, &clothes[i].b, &clothes[i].c);

	int re = 0;
	for (int i = 0; i < n; i++) {
		if (clothes[i].a <= days[0] && clothes[i].b >= days[0]) {
			int t = solve(1, clothes[i].c);
			if (t > re) re = t;
		}
	}

	printf("%d", re);
}