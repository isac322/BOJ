#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	unordered_set<string> set;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		reverse(str.begin(), str.end());
		const auto &p = set.find(str);
		if (p != set.end()) {
			printf("%zd %c", p->size(), p->at(p->size() / 2));
			return 0;
		}

		reverse(str.begin(), str.end());
		const auto &len = str.size() >> 1;
		bool check = true;
		for (auto i = 0; i < len; i++) {
			if (str[i] != str[str.size() - i - 1]) check = false;
		}
		if (check) {
			printf("%zd %c", str.size(),str[len]);
			return 0;
		}
		set.insert(str);
	}
}