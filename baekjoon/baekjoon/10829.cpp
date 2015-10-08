#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);

	string str = "";
	do {
		str.push_back(char(n & 1) + '0');
		n >>= 1;
	} while (n);
	reverse(str.begin(), str.end());
	puts(str.c_str());
}