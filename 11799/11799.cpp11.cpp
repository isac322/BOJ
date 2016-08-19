#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		long long n, y, m, arr[2] = { 0 };
		scanf("%lld %lld %lld %lld", arr, &n, &y, &m);

		for (int i = 0; i < n; i++) {
			if (arr[0] < arr[1]) swap(arr[0], arr[1]);
			arr[1] += arr[0];
		}
		if (arr[0] < arr[1]) swap(arr[0], arr[1]);
		arr[0] += y;

		long long &a = arr[0], &b = arr[1], q;
		while (b) {
			q = b;
			b = a%b;
			a = q;
		}
		printf("Case %d: %lld\n", c, a);
	}
}