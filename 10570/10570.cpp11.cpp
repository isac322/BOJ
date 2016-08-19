#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	short t, n, arr[1001], a;
	scanf("%hd", &t);
	while (t--) {
		fill(arr, arr + 1001, 0);
		scanf("%hd", &n);
		while (n--) {
			scanf("%hd", &a);
			arr[a]++;
		}
		short *p = arr;
		for (int i = 0; i < 1001; i++) {
			if (arr[i] > *p) p = arr + i;
		}
		printf("%d\n", p - arr);
	}
}