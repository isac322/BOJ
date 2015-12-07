#include <stdio.h>
#include <math.h>

char isPalindrome(int n) {
	int palindrome = 0;
	for (int i = n; i > 0; i /= 10) {
		palindrome *= 10;
		palindrome += i % 10;
	}
	if (palindrome == n) return 1;
	return 0;
}

char check[100000000] = { 1, 1 };
int main() {
	int a, b, t;
	scanf("%d %d", &a, &b);
	t = sqrt(b) + 1;
	for (int i = 2; i <= t; i++) if (!check[i]) for (int j = i << 1; j <= b; j += i) check[j] = 1;
	for (int i = a; i <= b; i++) if (!check[i] && isPalindrome(i)) printf("%d\n", i);
	puts("-1");
}