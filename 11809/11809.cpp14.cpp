#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(string n) {
	reverse(n.begin(), n.end());
	for (size_t i = 0; i < n.size();) {
		if (n[i] == 1) n.erase(n.begin() + i);
		else i++;
	}
	if (n.empty()) cout << "YODA\n";
	else {
		cout << stoi(n) << '\n';
	}
}

int main() {
	string n, m;
	cin >> n >> m;
	reverse(n.begin(), n.end());
	reverse(m.begin(), m.end());
	size_t len = min(m.size(), n.size());
	for (size_t i = 0; i < len; i++) {
		if (n[i] == m[i]) continue;
		else if (n[i] > m[i]) m[i] = 1;
		else n[i] = 1;
	}
	print(n);
	print(m);
}