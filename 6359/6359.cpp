#include <cstdio>
#include <bitset>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	bitset<101> bit;

	while (t--) {
		int n;
		scanf("%d", &n);
		bit.set();

		for (int i = 2; i <= n; i++) for (int j = i; j <= n; j += i) bit[j].flip();
		printf("%zd\n", bit.count() - 101 + n);
	}
}