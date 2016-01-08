#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	bool check[10000];
	while (scanf("%d", &n), n) {
		fill(check, check + 10000, false);
		int cnt = 0, t = n;
		do {
			check[t] = true;
			t = (t*t % 1000000) / 100;
			cnt++;
		} while (!check[t]);
		printf("%d\n", cnt);
	}
}