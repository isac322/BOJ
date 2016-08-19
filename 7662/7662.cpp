#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	multiset<int> st;
	int t;
	scanf("%d\n", &t);

	while (t--) {
		st.clear();
		int n;
		scanf("%d\n", &n);

		char op;
		int num;
		for (int i = 0; i < n; i++) {
			scanf("%c %d\n", &op, &num);

			if (op == 'I') {
				st.insert(num);
			}
			else {
				if (!st.empty()) {
					if (num == -1) st.erase(st.begin());
					else {
						multiset<int>::iterator i = st.end();
						i--;
						st.erase(i);
					}
				}
			}
		}

		if (st.empty()) {
			puts("EMPTY");
		}
		else {
			printf("%d %d\n", *st.rbegin(), *st.begin());
		}
	}
}