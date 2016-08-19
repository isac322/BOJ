#include <cstdio>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
	char p[202], t[101];
	int n, i = 0;
	scanf("%d\n", &n);
	while ((p[i] = getchar()) != 10) {
		if (p[i] == '*') {
			p[i] = '.';
			p[++i] = '*';
		}
		i++;
	}
	p[i] = 0;
	const auto &pp = regex(p);
	while (n--) puts(regex_match(gets(t), pp) ? "DA" : "NE");
}