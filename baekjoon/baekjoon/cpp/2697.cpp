#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);

	string str;
	while (n--) {
		cin >> str;
		if (next_permutation(str.begin(), str.end())) cout << str << '\n';
		else cout << "BIGGEST\n";
	}
}