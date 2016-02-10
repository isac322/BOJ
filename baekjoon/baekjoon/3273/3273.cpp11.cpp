#include <cstdio>

int arr[100000];
bool check[1000001];

int main() {
	int n, t, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		check[arr[i]] = true;
	}
	scanf("%d", &t);
	for (int i = 0; i < n; i++) if (t-arr[i] >= 0 && t-arr[i] <= 1000000 && check[t-arr[i]]) cnt++;
	printf("%d\n", cnt >> 1);
}