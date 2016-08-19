#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[50010], dp[50010];
int len;

bool solve(int index) {
	if (index == len) return true;

	char &p = dp[index];
	if (p != -1) return p == 1;
	p = 0;

	const char &ch = str[index];

	switch (ch) {
		case 'b':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'c':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'f':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'h':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'i':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'k':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'n':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'o':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'p':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 's':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'u':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'v':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'w':
			if (solve(index + 1)) return (p = 1) == 1;
			break;
		case 'y':
			if (solve(index + 1)) return (p = 1) == 1;
	}

	if (index > len - 2) return false;
	const char &next = str[index + 1];
	switch (ch) {
		case 'a':
			if (next == 'c' || next == 'g' || next == 'l' || next == 'm' || next == 'r' || next == 's' || next == 't' || next == 'u') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'b':
			if (next == 'a' || next == 'e' || next == 'h' || next == 'i' || next == 'k' || next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'c':
			if (next == 'a' || next == 'd' || next == 'e' || next == 'f' || next == 'l' || next == 'm' || next == 'n' || next == 'o' || next == 'r' || next == 's' || next == 'u') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'd':
			if (next == 'b' || next == 's' || next == 'y') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'e':
			if (next == 'r' || next == 's' || next == 'u') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'f':
			if (next == 'e' || next == 'l' || next == 'm' || next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'g':
			if (next == 'a' || next == 'd' || next == 'e') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'h':
			if (next == 'e' || next == 'f' || next == 'g' || next == 'o' || next == 's') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'i':
			if (next == 'n' || next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'k':
			if (next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'l':
			if (next == 'a' || next == 'i' || next == 'r' || next == 'u' || next == 'v') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'm':
			if (next == 'd' || next == 'g' || next == 'n' || next == 'o' || next == 't') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'n':
			if (next == 'a' || next == 'b' || next == 'd' || next == 'e' || next == 'i' || next == 'o' || next == 'p') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'o':
			if (next == 's') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'p':
			if (next == 'a' || next == 'b' || next == 'd' || next == 'm' || next == 'o' || next == 'r' || next == 't' || next == 'u') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'r':
			if (next == 'a' || next == 'b' || next == 'e' || next == 'f' || next == 'g' || next == 'h' || next == 'n' || next == 'u') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 's':
			if (next == 'b' || next == 'c' || next == 'e' || next == 'g' || next == 'i' || next == 'm' || next == 'n' || next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 't':
			if (next == 'a' || next == 'b' || next == 'c' || next == 'e' || next == 'h' || next == 'i' || next == 'l' || next == 'm') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'x':
			if (next == 'e') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'y':
			if (next == 'b') if (solve(index + 2)) return (p = 1) == 1;
			break;
		case 'z':
			if (next == 'n' || next == 'r') if (solve(index + 2)) return (p = 1) == 1;
			break;
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%s", str);
		len = strlen(str);
		fill_n(dp, len, -1);

		printf("%s\n", solve(0) ? "YES" : "NO");
	}
}