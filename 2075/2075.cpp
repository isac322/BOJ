#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n, t, a;
	scanf("%d", &n);

	int num[1500], index = 0;
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &t);

		if (index == n) {
			if (num[0] < t) {
				pop_heap(num, num + n, greater<int>());
				num[n - 1] = t;
				push_heap(num, num + n, greater<int>());
			}
		}
		else {
			num[index++] = t;
			push_heap(num, num + index, greater<int>());
		}
	}
	printf("%d", num[0]);
}