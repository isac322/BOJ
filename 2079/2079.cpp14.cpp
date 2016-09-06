#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class OnlinePalindromeChecker {
private:
	/* Number of characters in the alphabet */
	const int d;

	/* modulo constant */
	const int M;

	/* hashcode of first half and second half */
	long long half1 = 0, half2 = 0;

	long long coefficient = 1;
	std::string s;

public:
	OnlinePalindromeChecker(const int d = 26, const int M = 1'000'000'007) : d(d), M(M) {}

	bool insertChar(const char ch) {
		s.push_back(ch);

		const std::size_t len = s.size();

		if (len < 3) {
			if (len == 1) {
				half1 = ch % M;
				return true;
			}
			else if (len == 2) {
				half2 = ch % M;
				return s[0] == s[1];
			}
		}
		else if (len & 1) {
			half2 = (d*(M + half2 - (s[len / 2] * coefficient) % M) % M + ch) % M;
		}
		else {
			coefficient = coefficient*d % M;
			half1 = (half1 + coefficient*s[len / 2 - 1]) % M;

			half2 = (half2*d + ch) % M;
		}

		if (half1 == half2) {
			bool isPalindrome = true;

			for (int i = 0; i < len / 2; i++) {
				if (s[i] != s[len - i - 1]) isPalindrome = false;
			}

			return isPalindrome;
		}
		else return false;
	}
};

char str[2001];
int dp[2000], n;

int solve(int index) {
	if (index >= n) return 0;
	int &p = dp[index];
	if (p != -1) return p;

	OnlinePalindromeChecker checker;
	p = n - index - 1;

	for (int i = index; i < n; i++) {
		if (checker.insertChar(str[i] - 'a')) {
			p = min(p, solve(i + 1));
		}
	}

	return ++p;
}

int main() {
	scanf("%s", str);
	n = strlen(str);
    fill_n(dp, n, -1ll);
	printf("%d", solve(0));
}