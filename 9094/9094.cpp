#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int cnt = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				double d = (i*i + j*j + m) / double(i*j);
				int tmp = int(d);
				if (d == double(tmp)) cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}