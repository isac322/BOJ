#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int arr[2] = { 0 }, prev = 0, score[2] = { 0 };

	for (int i = 0; i < n; i++) {
		int t, h, m;
		scanf("%d %d:%d", &t, &h, &m);
		m += h * 60;

		if (score[0] > score[1]) {
			arr[0] += m - prev;
		} else if (score[0] < score[1]) {
			arr[1] += m - prev;
		}

		score[t - 1]++;
		prev = m;
	}

	int m = 48 * 60;
	if (score[0] > score[1]) {
		arr[0] += m - prev;
	} else if (score[0] < score[1]) {
		arr[1] += m - prev;
	}

	printf("%02d:%02d\n", arr[0] / 60, arr[0] % 60);
	printf("%02d:%02d", arr[1] / 60, arr[1] % 60);
}