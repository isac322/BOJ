#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, t, sum = 0, m = 1 << 31;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (sum < 0) sum = t;
		else sum += t;

		m = max(m, sum);
	}
	printf("%d", m);
}