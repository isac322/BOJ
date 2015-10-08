#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		bool check = true;
		for (int j = 0; j < 10; ++j) {
			int t;
			cin >> t;
			if (j % 5 + 1 != t) check = false;
		}
		if (check) cout << i << '\n';
	}
}