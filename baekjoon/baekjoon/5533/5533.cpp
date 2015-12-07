#include <cstdio>

using namespace std;

int main() {
	int n, arr[200][3], sum[200] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", arr[i], arr[i] + 1, arr[i] + 2);

	for (int i = 0; i < 3; i++) {
		char flag[101] = {0};
		for (int j = 0; j < n; ++j) flag[arr[j][i]]++;
		for (int j = 0; j < n; ++j) if (flag[arr[j][i]] == 1) sum[j] += arr[j][i];
	}
	for (int i = 0; i < n; i++) printf("%d\n", sum[i]);
}