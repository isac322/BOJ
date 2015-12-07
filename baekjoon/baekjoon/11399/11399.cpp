#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	short n, arr[1001];
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) scanf("%hd", arr + i);
	sort(arr, arr + n);
	int sum, tot;
	sum = tot = arr[0];
	for (short i = 1; i < n; i++) {
		tot += arr[i];
		sum += tot;
	}
	printf("%d", sum);
}