#include <cstdio>

int arr[100000], index, sum;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + index);
		if (arr[index]) index++;
		else index--;
	}
	for (int i = 0; i < index; i++) sum += arr[i];
	printf("%d", sum);
}