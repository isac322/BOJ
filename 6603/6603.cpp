#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int left;
int arr[13];

int main() {
	while (true) {
		scanf("%d", &n);
		if (!n) break;

		left = n - 6;
		for (int i = 0; i < n; i++) scanf("%d", arr + i);

		for (size_t i1 = 0; i1 <= left && i1 < n; i1++) {
			for (size_t i2 = i1 + 1; i2 <= i1 + 1 + left && i2 < n; i2++) {
				for (size_t i3 = i2 + 1; i3 <= i2 + 1 + left && i3 < n; i3++) {
					for (size_t i4 = i3 + 1; i4 <= i3 + 1 + left && i4 < n; i4++) {
						for (size_t i5 = i4 + 1; i5 <= i4 + 1 + left && i5 < n; i5++) {
							for (size_t i6 = i5 + 1; i6 <= i5 + 1 + left && i6 < n; i6++) {
								printf("%d %d %d %d %d %d\n", arr[i1], arr[i2], arr[i3], arr[i4], arr[i5], arr[i6]);
							}
						}
					}
				}
			}
		}
		puts("");
	}
}