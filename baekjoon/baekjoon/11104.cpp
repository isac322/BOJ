#include <cstdio>

using namespace std;

int main() {
	int t, n;
	scanf("%d\n", &t);
	char ch;
	while (t--) {
		n = 0;
		for (int i = 23; i >= 0; i--) {
			n <<= 1;
			ch = getchar();
			n += ch - '0';
		}
		printf("%d\n", n);
		getchar();
	}
}