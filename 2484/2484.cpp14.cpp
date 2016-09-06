#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, a, M = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c = 0;
		map<int, int> m;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &a);
			m[a]++;
		}
		auto j = m.begin();
		switch (m.size()) {
			case 1: c = 50000 + j->first * 5000;
				break;
			case 2:
				if (j->second == 2) c = 2000 + j->first * 500 + m.rbegin()->first * 500;
				else {
					if (j->second != 3) j++;
					c = 10000 + j->first * 1000;
				}
				break;
			case 3:
				while (j->second != 2) j++;
				c = 1000 + j->first * 100;
				break;
			case 4:
				c = m.rbegin()->first * 100;
		}
		M = max(M, c);
	}
	printf("%d", M);
}