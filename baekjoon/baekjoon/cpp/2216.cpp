#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str1[3001], str2[3001];
int dp[3001][3001], a, b, c, len1, len2;
bool visited[3001][3001];

int solve(int idx, int idx2) {
	int &p = dp[idx][idx2];
	if (visited[idx][idx2]) return p;
	p = 0;

	if (idx == len1 && idx2 == len2) return 0;

	if (idx != len1) {
		p = solve(idx + 1, idx2) + b;
		visited[idx][idx2] = true;
	}
	if (idx2 != len2) {
		if (visited[idx][idx2]) p = max(p, solve(idx, idx2 + 1) + b);
		else {
			visited[idx][idx2] = true;
			p = solve(idx, idx2 + 1) + b;
		}
	}
	if (idx != len1 && idx2 != len2) {
		p = max(p, solve(idx + 1, idx2 + 1) + (str1[idx] == str2[idx2] ? a : c));
	}

	return p;
}

int main() {
	scanf("%d %d %d\n", &a, &b, &c);
	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	printf("%d", solve(0, 0));
}