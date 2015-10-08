#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		double d;
		int cnt = 0;
		scanf("%d %lf", &n, &d);

		for (int i = 0; i < n; ++i) {
			int v, f, c;
			scanf("%d %d %d", &v, &f, &c);

			if (d / v * c <= f) cnt++;
		}
		printf("%d\n", cnt);
	}
}