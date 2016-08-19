#include <cstdio>
#include <algorithm>

using namespace std;

int t[2];
int main() {
	char p = getchar(), c;
	while ((c = getchar()) != -1) {
		if (p != c) t[p - '0']++;
		p = c;
	}
	t[p - '0']++;
	printf("%d", min(t[0], t[1]));
}