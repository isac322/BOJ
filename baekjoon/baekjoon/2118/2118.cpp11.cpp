#include <cstdio>
#include <algorithm>

using namespace std;

int arr[50000];

int main() {
	int n, cw, ccw = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		ccw += arr[i];
	}

	ccw -= arr[0];
	cw = arr[0];

	int maximum = min(cw, ccw), s = 0, e = 1;

	while (e < n) {
		while (min(cw - arr[s], ccw + arr[s]) > min(cw, ccw)) {
			cw -= arr[s];
			ccw += arr[s];

			s++;
		}

		maximum = max(min(cw, ccw), maximum);

		cw += arr[e];
		ccw -= arr[e];

		e++;
	}

	printf("%d", maximum);
}