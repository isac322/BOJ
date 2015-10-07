#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int ii = 1; ii <= t; ++ii) {
		scanf("%d", &ii);

		int cnt = 0, pivot = 0, num;
		for (int i = 0; i < 15; i++) {
			scanf("%d", &num);

			if (num > pivot) {
				cnt++;
				pivot = num;
			}
			else if (num < pivot) pivot = num;
		}
		printf("%d %d\n", ii, cnt);
	}
}