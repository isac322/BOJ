#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string a;
	cin >> a;
	int n;
	scanf("%d", &n);

	int sum = 0, len = a.length();
	for (int i = 0, q = 1; i < len; i++, q *= n) {
		char &t = a[len - i - 1];

		if (t >= '0'&&t <= '9') sum += (t - '0')*q;
		else sum += (t - 'A' + 10)*q;
	}

	printf("%d", sum);
}