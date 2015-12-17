#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	char a[21];
	int n, b, t;
	scanf("%d", &t);

	while (t--) {
		pair<int, string> s(0, "");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %d", a, &b);
			s = max(s, make_pair(b, string(a)));
		}
		puts(s.second.c_str());
	}
}