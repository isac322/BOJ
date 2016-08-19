#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[2001];
int dp[2000], n;

bool isPalindrome(int s, int e) {
	bool check = true;

	while (e - s >= 2) {
		if (str[e] != str[s]) check = false;
		e--, s++;
	}
	if (str[e] != str[s]) check = false;

	return check;
}

int solve(int index) {
	if (index >= n) return 0;
	int &p = dp[index];
	if (p != -1) return p;

	p = n - index - 1;

	for (int i = index; i < n; i++) {
		if (isPalindrome(index, i)) {
			p = min(p, solve(i + 1));
		}
	}

	return ++p;
}

int main() {
	scanf("%s", str);
	n = strlen(str);
    fill_n(dp, n, -1);
	printf("%d", solve(0));
}