#include <stdio.h>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
	char str[9];
	int m, d;
	bitset<20> set;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s", str);

		switch (str[0]) {
			case 'a':
				if (str[1] == 'd') {
					scanf("%d", &d);
					set.set(d - 1);
				}
				else set.set();
				break;
			case 'c':
				scanf("%d", &d);
				puts(set.test(d - 1) ? "1" : "0");
				break;
			case 'e':
				set.reset();
				break;
			case 't':
				scanf("%d", &d);
				set.flip(d - 1);
				break;
			case 'r':
				scanf("%d", &d);
				set.reset(d - 1);
		}
	}
}