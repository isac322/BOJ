#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	int t, ch;
	scanf("%d\n", &t);
	list<char> l;

	while (t--) {
		l.clear();

		auto iter = l.begin();
		while ((ch = getchar()) != 10 && ch != -1) {
			switch (ch) {
				case '<':
					if (iter != l.begin()) iter--;
					break;
				case '>':
					if (iter != l.end()) iter++;
					break;
				case '-':
					if (iter != l.begin()) iter = l.erase(--iter);
					break;
				default:
					iter = ++l.insert(iter, ch);
			}
		}

		for (const char &c : l) putchar(c);
		puts("");
	}
}