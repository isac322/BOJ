#include <iostream>
#include <string>

using namespace std;

int main() {
	string str, t;
	int n, cnt = 0;
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		t += t;
		if (t.find(str) < t.size()) cnt++;
	}
	cout << cnt;
}