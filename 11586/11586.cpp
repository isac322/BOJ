#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, t;
	scanf("%d\n", &n);

	char str[100][101];
	for (int i = 0; i < n; i++) gets(str[i]);
	scanf("%d", &t);
	switch (t) {
		case 1: for (int i = 0; i < n; i++) puts(str[i]);
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) putchar(str[i][j]);
				puts("");
			}
			break;
		case 3:
			for (int i = n - 1; i >= 0; i--) puts(str[i]);
	}
}