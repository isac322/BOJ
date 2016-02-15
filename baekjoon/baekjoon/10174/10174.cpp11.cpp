#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, str);
		size_t len = str.size();

		bool check = true;
		for (size_t i = 0; i < (len + 1) >> 1; i++) {
			if (tolower(str[i]) != tolower(str[len - i - 1])) {
				check = false;
				break;
			}
		}
		cout << (check ? "Yes\n" : "No\n");
	}
}