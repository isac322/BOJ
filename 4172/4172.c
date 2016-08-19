#include <stdio.h>
#include <math.h>

int arr[1000001] = { 1 };
int main() {
	int a, b, c;
	double tmp;
	for (int i = 1; i < 1000001; i++) {
		tmp = sin((double) i);
		a = (int) (i - sqrt((double) i));
		b = (int) log((double) i);
		c = (int) (i*tmp*tmp);
		arr[i] = (arr[a] + arr[b] + arr[c]) % 1000000;
	}
	while (scanf("%d", &a) && a != -1) {
		printf("%d\n", arr[a]);
	}
}