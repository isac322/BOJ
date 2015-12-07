#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a, b, t;
	string str;
	while (scanf("R%dC%d\n", &a, &b), a || b) {
		t = b;
		str.clear();
		while (t) {
			str.push_back(--t % 26 + 'A');
			t /= 26;
		}
		reverse(str.begin(), str.end());
		printf("%s%d\n", str.c_str(), a);
	}
}