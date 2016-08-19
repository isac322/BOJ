#include <cstdio>
#include <set>

short r[1000], a, b;

short find(short p) {
	if (p == r[p]) return p;
	return r[p] = find(r[p]);
}

void uni(int p, int q) {
	p = find(p);
	q = find(q);
	r[q] = p;
}

int main() {
	int n, m, cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) r[i] = i;
	while (m--) {
		scanf("%hd%hd", &a, &b);
		a--, b--;
		uni(a, b);
	}
	std::set<short> s;
	for (int i = 0; i < n; i++) s.emplace(find(i));
	printf("%zd", s.size());
}