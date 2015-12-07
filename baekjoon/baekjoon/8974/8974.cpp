#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int a, b, sum = 0, num = 1, t, t1;
	scanf("%d%d", &a, &b);

	bool check = true;
	while (check) {
		for (int i = 0; i < num; i++) {
			if (--a == 0) t = sum;
			sum += num;
			if (--b == 0) {
				t1 = sum;
				check = false;
			}
		}

		num++;
	}
	printf("%d", t1 - t);
}