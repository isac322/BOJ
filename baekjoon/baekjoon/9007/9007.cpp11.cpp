#include <stdio.h>
#include <algorithm>

using namespace std;


int sum1[1000000], sum2[1000000];

int main() {
	int case_n;

	scanf("%d", &case_n);

	while (case_n--) {
		int k, n, tmp;
		scanf("%d %d", &k, &n);
		int max = n * n;

		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			fill_n(sum1 + j*n, n, tmp);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			for (int i = j; i < max; i += n) {
				sum1[i] += tmp;
			}
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			fill_n(sum2 + j*n, n, tmp);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			for (int i = j; i < max; i += n) {
				sum2[i] += tmp;
			}
		}

		sort(sum1, sum1 + max);
		sort(sum2, sum2 + max);


		int min = 0x7fffffff;
		int val = 0;
		for (int i = 0; i < max; i++) {
			int find = k - sum1[i];
			int index = upper_bound(sum2, sum2 + max, find) - sum2;

			int dif, re;
			if (index == max) index--;
			
			if (index == 0) {
				dif = find - sum2[index];
				re = sum1[i] + sum2[index];
			} else {
				dif = find - sum2[index];
				re = sum1[i] + sum2[index];
				if ((abs(dif) > abs(find - sum2[index - 1])) || (abs(dif) == abs(find - sum2[index - 1]) && dif < find - sum2[index - 1])) {
					dif = find - sum2[index - 1];
					re = sum1[i] + sum2[index - 1];
				}
			}

			if (abs(dif) < abs(min) || (abs(dif) == abs(min) && dif > min)) {
				min = dif;
				val = re;
			}
		}

		printf("%d\n", val);
	}
}