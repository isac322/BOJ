#include <cstdio>
#include <algorithm>

using namespace std;

int n, dp[15];
char t[15];
short p[15];

int solve(int day) {
    if (day >= n) return 0;
    else if (dp[day] != -1) return dp[day];
    return dp[day] = max(day + t[day] <= n ? (p[day] + solve(day + t[day])) : 0, solve(day + 1));
}

int main() {
    fill(dp, dp + 15, -1);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%hhd%hd", t + i, p + i);
    printf("%d", solve(0));
}