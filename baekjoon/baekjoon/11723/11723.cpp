#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

inline bool test(int pos) {
	return (n >> pos) & 1;
}

inline void add(int pos) {
	n |= 1 << pos;
}

inline void remove(int pos) {
	n &= ~(1 << pos);
}

int main() {
	char str[9];
	int m, d;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s", str);

		switch (str[0]) {
			case 'a':
				if (str[1] == 'd') {
					scanf("%d", &d);
					add(d);
				}
				else n = -1;
				break;
			case 'c':
				scanf("%d", &d);
				puts(test(d) ? "1" : "0");
				break;
			case 'e':
				n = 0;
				break;
			case 't':
				scanf("%d", &d);
				n ^= 1 << d;
				break;
			case 'r':
				scanf("%d", &d);
				remove(d);
		}
	}
}