#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, n1;
	char c;
	scanf("%d\n", &n);
	while (true) {
		scanf("%c\n", &c);
		if (c == '=') break;
		scanf("%d\n", &n1);
		switch (c) {
			case '+': n += n1; break;
			case '-': n -= n1; break;
			case '*': n *= n1; break;
			case '/': n /= n1; break;
		}
	}
	printf("%d", n);
}