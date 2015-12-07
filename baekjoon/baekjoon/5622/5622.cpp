#include <cstdio>

using namespace std;

int main() {
	const char arr[] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	char str[16];
	gets(str);
	int sum = 0;
	for (int i = 0; str[i]; i++) {
		sum += arr[str[i] - 65] + 1;
	}
	printf("%d\n", sum);
}