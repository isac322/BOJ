#include <cstdio>
#include <algorithm>

using namespace std;

int post[100000], match[100001];

void solve(int root_pos, int length, int start) {
	if (length < 1 || root_pos < start) return;
	printf("%d ", post[root_pos]);
	if (length == 1) return;

	const int &pos = match[post[root_pos]];
	int middle = start;
	for (; match[post[middle]] < pos; middle++);
	solve(middle - 1, middle - start, start);
	solve(root_pos - 1, root_pos - middle + 1, middle);
}

int main() {
	int n, t;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		match[t] = i;
	}
	for (int i = 0; i < n; i++) scanf("%d", post + i);

	solve(n - 1, n, 0);
}