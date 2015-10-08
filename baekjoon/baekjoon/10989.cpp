#include <cstdio>

using namespace std;

int main() {
	int arr[10001] = {0}, n, t;
	register int i = 0, j;
	scanf("%d", &n);
	for (; i < n; i++) {
		scanf("%d", &t);
		arr[t]++;
	}
	register char str[8];
	for (i = 1; i < 10001; i++) {
		sprintf(str, "%d", i);
		for (j = 0; j < arr[i]; j++) puts(str);
	}
}