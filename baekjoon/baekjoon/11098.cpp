#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;

	while (c--) {
		int n;
		cin >> n;

		pair<int, string> m(0, ""), t;
		while (n--) {
			cin >> t.first >> t.second;
			m = max(m, t);
		}

		cout << m.second << '\n';
	}
}