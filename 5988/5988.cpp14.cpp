#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int n;
	scanf("%d\n", &n);
	while (n--) {
		getline(cin, str);
		puts(str.back() & 1 ? "odd" : "even");
	}
}