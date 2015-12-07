#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;

	while (n--) {
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << '\n';
	}
}