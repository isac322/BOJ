#include <cstdio>

int main() {
	int cnt = 0;
	char str[4];
	while (~scanf("%3s", str)) {
		if (str[0] != 'P') cnt++;
		if (str[1] != 'E') cnt++;
		if (str[2] != 'R') cnt++;
	}
	printf("%d", cnt);
}