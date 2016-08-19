#include <cstdio>
#include <set>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	set<int> s;

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);

		s.insert(t);
	}

	for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
		printf("%d ", *i);
	}
}