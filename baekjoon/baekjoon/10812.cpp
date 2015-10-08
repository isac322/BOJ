#include <cstdio>

using namespace std;

int main() {
	int n, m, arr[101], tmp[101];
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) arr[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		for (int j = c; j <= b; j++) tmp[a + j - c] = arr[j];
		for (int j = a; j < c; j++) tmp[b - c + j + 1] = arr[j];
		for (int j = a; j <= b; j++) arr[j] = tmp[j];
	}
	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
}