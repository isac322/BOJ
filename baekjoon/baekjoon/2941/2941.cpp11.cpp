#include <cstdio>
#include <algorithm>

using namespace std;

char str[105];
int len = 0;

int solve(int pos) {
	if (pos >= len) return 0;
	switch (str[pos]) {
		case 'c': return solve(str[pos + 1] == '=' || str[pos + 1] == '-' ? pos + 2 : pos + 1) + 1;
		case 'd':
			if (str[pos + 1] == 'z' && str[pos + 2] == '=') return solve(pos + 3) + 1;
			else if (str[pos + 1] == '-') return solve(pos + 2) + 1;
			else return solve(pos + 1) + 1;
		case 'l': return solve(str[pos + 1] == 'j' ? pos + 2 : pos + 1) + 1;
		case 'n': return solve(str[pos + 1] == 'j' ? pos + 2 : pos + 1) + 1;
		case 's': return solve(str[pos + 1] == '=' ? pos + 2 : pos + 1) + 1;
		case 'z': return solve(str[pos + 1] == '=' ? pos + 2 : pos + 1) + 1;
		default: return solve(pos + 1) + 1;
	}
}

int main() {
	while ((str[len] = getchar()) != '\n' && str[len] != -1) len++;
	printf("%d", solve(0));
}