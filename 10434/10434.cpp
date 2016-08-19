#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	bool prime[10001] = {true, true};
	for (int i = 2; i <= 100; i++) if (!prime[i]) for (int j = i << 1; j <= 10000; j += i) prime[j] = true;

	bool arr[333];
	char str[5];
	while (t--) {
		int c, n;
		scanf("%d %d", &c, &n);
		if (prime[n]) {
			printf("%d %d NO\n", c, n);
			continue;
		}
		int num = n;

		fill_n(arr, 333, false);
		bool check;
		while (true) {
			sprintf(str, "%d", n);
			n = 0;
			for (int i = 0; str[i]; i++) n += (str[i] - '0') * (str[i] - '0');

			if (n == 1) {
				check = true;
				break;
			}
			else if (arr[n]) {
				check = false;
				break;
			}

			arr[n] = true;
		}

		printf("%d %d %s\n", c, num, check ? "YES" : "NO");
	}
}