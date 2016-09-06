#include <cstdio>
#include <algorithm>

using namespace std;

int post[100000], match[100001];

void solve(int root_pos, int length, int start, int fix) {
	if (length < 1 || root_pos < start) return;
	printf("%d ", post[root_pos], root_pos);

	const int &pos = match[post[root_pos]] - fix;
	solve(pos - 1, pos - start, start, fix);
	solve(root_pos - 1, root_pos - pos, pos, fix + 1);
}

int main() {
	int n, t;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		match[t] = i;
	}
	for (int i = 0; i < n; i++) scanf("%d", post + i);

	solve(n - 1, n, 0, 0);
}