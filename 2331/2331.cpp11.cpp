#include <cstdio>
#include <set>

using namespace std;

set<int> s;

int a, p;

inline int g(int q) {
	int a = 0, t, i;
	for (; q; q /= 10) {
		for (i = 0, t = 1; i < p; i++) t *= q % 10;
		a += t;
	}
	return a;
}

int main() {
	scanf("%d%d", &a, &p);
	auto iter = s.end();
	while ((iter = s.find(a)) == s.end()) {
		s.emplace(a);
		a = g(a);
	}
	while ((iter = s.find(a)) != s.end()) {
		s.erase(iter);
		a = g(a);
	}
	printf("%zd", s.size());
}