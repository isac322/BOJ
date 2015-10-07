#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
	int t;
	scanf("%d\n", &t);
	char ch;
	bitset<24> set;
	while (t--) {
		for (int i = 23; i >= 0; i--) {
			ch = getchar();
			if (ch == '0') set.reset(i);
			else set.set(i);
		}
		printf("%u\n", set.to_ulong());
		getchar();
	}
}