#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, arr[100], re = 300000, sum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= m) re = min(re, m - sum);
			}
		}
	}
	printf("%d", m - re);
}