#include <cstdio>
#include <map>

using namespace std;

int main() {
	int n, a, b;
	long long sum = 0;
	scanf("%d", &n);

	map<int, long long> x, y;

	while (n--) {
		scanf("%d %d", &a, &b);

		x[a]++;
		y[b]++;
	}

	map<int, long long>::iterator i;
	for (i = x.begin(); i != x.end(); i++) {
		long long &n = i->second;

		if (n > 1LL) sum++;
	}
	for (i = y.begin(); i != y.end(); i++) {
		long long &n = i->second;

		if (n > 1LL) sum++;
	}

	printf("%lld", sum);
}