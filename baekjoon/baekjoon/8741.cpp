#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) putchar('1');
	for (int i = 1; i < n; i++) putchar('0');
}