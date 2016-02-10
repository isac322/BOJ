#include <cstdio>
#include <algorithm>

using namespace std;

inline bool isPrime(long long n) {
	if (n <= 1LL) return false;
	else if (n <= 3LL) return true;
	else if (n % 2LL == 0LL || n % 3LL == 0LL) return false;
	for (long long i = 5LL; i*i <= n; i += 6LL) if (n%i == 0LL || n % (i + 2LL) == 0LL) return false;
	return true;
}

int main() {
	long long n;
	scanf("%lld", &n);
	if (isPrime(n)) {
		char str[17];
		sprintf(str, "%lld", n);
		int i = 0;
		for (; str[i]; i++) {
			switch (str[i]) {
				case '6': str[i] = '9'; break;
				case '9': str[i] = '6'; break;
				case '3':
				case '4':
				case '7':
					puts("no");
					return 0;
				default:
					break;
			}
		}
		reverse(str, str + i);
		if (isPrime(atoll(str))) puts("yes");
		else puts("no");
	}
	else puts("no");
}