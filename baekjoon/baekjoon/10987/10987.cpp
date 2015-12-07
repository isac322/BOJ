#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;
	for (size_t i = 0; i < str.size(); i++) {
		switch (str[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				cnt++;
		}
	}
	cout << cnt;
}