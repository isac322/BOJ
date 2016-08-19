#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	short arr[145], len = 0, n;
	for (short i = 1; i < 100; i++) arr[len++] = i;
	for (short i = 1; i < 10; i++) {
		for (short j = i / 2; j > 0; j--) arr[len++] = i * 100 + (i - j) * 10 + i - j * 2;
		arr[len++] = i * 100 + i * 10 + i;
		for (short j = 1; i + j * 2 < 10; j++) arr[len++] = i * 100 + (i + j) * 10 + i + j * 2;
	}
	scanf("%hd", &n);
	printf("%zd", upper_bound(arr, arr + 144, n) - arr);
}