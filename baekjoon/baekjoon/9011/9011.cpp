#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

int result[100] = { 0 };

int main() {
	list<int> l;
	int case_n;
	scanf("%d", &case_n);

	while (case_n--) {
		l.clear();

		bool flag = false;
		int n, t;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &t);

			if (t > i) flag = true;
			if (!flag) {
				list<int>::iterator iter = l.begin();
				for (int j = 0; j < t; j++) iter++;
				l.insert(iter, i);
			}

		}

		if (flag) {
			puts("IMPOSSIBLE");
		} else {
			int i = 1;
			for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++, i++) {
				result[*iter] = i;
			}

			for (i = 0; i < n; i++) {
				printf("%d ", result[i]);
			}
			puts("");
		}
	}
}