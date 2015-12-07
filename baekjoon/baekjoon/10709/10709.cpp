#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	char ch;
	int n, m;
	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; i++) {
		bool start = false;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			ch = getchar();
			if (ch == 'c') {
				cnt = 0;
				printf("0 ");
				start = true;
			}
			else {
				if (start) {
					cnt++;
					printf("%d ", cnt);
				}
				else printf("-1 ");
			}
		}
		getchar();
	}
}