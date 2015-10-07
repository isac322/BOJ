#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int t, len;
	scanf("%d\n", &t);
	char str[10010];
	while (t--) {
		for (len = 0; (str[len++] = getchar()) != 10;);
		int sq = sqrt(len);
		for (int i = sq - 1; i >= 0; i--) for (int j = 0; j < sq; j++) putchar(str[i + j*sq]);
		puts("");
	}
}