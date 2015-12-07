#include <cstdio>
#include <algorithm>

using namespace std;

int get(int n, int k) {
	if (n <= 0 || k < 0) return 0;
	else if (n == k || k == 0) return 1;
	return get(n - 1, k) + get(n - 1, k - 1);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", get(n, k));
}