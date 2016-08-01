#include <cstdio>
#include <algorithm>

using namespace std;

short n, dp1[1000], arr[1000], m = 0;

int main() {
	scanf("%hd", &n);
	for (short i = n - 1; i >= 0; i--) scanf("%hd", arr + i);
	dp1[0] = 1;
	for (short i = 1; i < n; i++) {
		for (short j = i - 1; j >= 0; j--) if (arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j]);
		m = max(++dp1[i], m);
	}
	printf("%hd", m);
}