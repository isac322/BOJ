#include <cstdio>

using namespace std;

int main() {
	char str[31];
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(str);
		if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
		puts(str);
	}
}