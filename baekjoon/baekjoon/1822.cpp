#include <cstdio>
#include <map>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, bool> ma;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ma[t] = true;
	}

	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		
		ma.erase(t);
	}

	printf("%d\n", ma.size());
	for (map<int, bool>::iterator i = ma.begin(); i != ma.end(); i++) {
		printf("%d ", i->first);
	}
}