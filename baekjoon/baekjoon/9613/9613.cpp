#include <cstdio>

using namespace std;

inline int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	int t, arr[100];
	scanf("%d", &t);

	while (t--) {
		int n, sum = 0;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) scanf("%d", arr + i);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				sum += (arr[i] < arr[j] ? gcd(arr[j], arr[i]) : gcd(arr[i], arr[j]));
			}
		}
		printf("%d\n", sum);
	}
}