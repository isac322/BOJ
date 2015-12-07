#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
	return a*b / gcd(a, b);
}

int main() {
	int arr[5];
	scanf("%d%d%d%d%d", arr, arr + 1, arr + 2, arr + 3, arr + 4);
	int num = lcm(lcm(arr[0], arr[1]), arr[2]);
	for (int i = 0; i < 3; i++) for (int j = i + 1; j < 4; j++) for (int k = j + 1; k < 5; k++) num = min(num, lcm(lcm(arr[i], arr[j]), arr[k]));
	printf("%d", num);
}