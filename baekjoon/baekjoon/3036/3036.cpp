#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	scanf("%d", &n);
	int first;
	scanf("%d", &first);
	for (int i = 1; i < n; i++) {
		int a;
		scanf("%d", &a);
		const int &ret = gcd(first, a);
		printf("%d/%d\n", first / ret, a / ret);
	}
}