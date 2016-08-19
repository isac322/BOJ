#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	bool v;
	string p, h;
	scanf("%d\n", &n);
	getline(cin, h);
	getline(cin, p);
	v = h < p;
	for (int i = 2; i < n; i++) {
		getline(cin, h);
		if ((p < h) != v) {
			puts("NEITHER");
			return 0;
		}
		swap(h, p);
	}
	puts(v ? "INCREASING" : "DECREASING");
}