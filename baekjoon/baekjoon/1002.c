#include <stdio.h>
#include <math.h>

int main() {
	int max, i, dis, r, num1[3], num2[3], tmp;

	scanf("%d", &max);

	while (max--) {
		for (i = 0; i < 3; i++) scanf("%d", num1 + i);
		for (i = 0; i < 3; i++) scanf("%d", num2 + i);

		dis = pow(num2[0] - num1[0],2) + pow(num2[1] - num1[1],2);
		r = pow(num1[2] + num2[2],2);
		if (dis == r) puts("1");
		else if (dis < r) {
            tmp = pow(num1[2] - num2[2],2);
			if (dis == 0 && num1[2] == num2[2]) puts("-1");
			else if (dis == tmp) puts("1");
			else if (dis > tmp) puts("2");
			else puts("0");
		}
		else puts("0");
	}
}