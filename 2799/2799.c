#include <stdio.h>

int main() {
	int n, m, count[5] = {0};
	char tmp[602];
	scanf("%d %d\n", &n, &m);
	gets(tmp);

	for (int i = 0; i < n; ++i) {
		int windows[602] = {0};

		for (int k = 0; k < 4; ++k) {
			gets(tmp);

			for (int j = 0, t = 1; j < m; ++j, t += 5) {
				if (tmp[t] == '*') windows[j]++;
			}
		}

		for (int j = 0; j < m; ++j) count[windows[j]]++;

		gets(tmp);
	}

	for (int i = 0; i < 5; ++i) printf("%d ",count[i]);
}