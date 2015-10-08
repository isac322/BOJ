#include <cstdio>

using namespace std;

int main() {
	int a, b, i = 0;
	char arr[10] = "";
	scanf("%d %d", &a, &b);

	while (a + b) {
		arr[i++] = a % 10 + b % 10;
		a /= 10;
		b /= 10;
	}
	for (int j = i - 1; j >= 0; j--) printf("%d", arr[j]);
}