#include <iostream>
#include <string>

using namespace std;

int main() {
	string day;
	cin >> day;

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		string st;
		cin >> st;

		if (*st.rbegin() == *day.rbegin()) cnt++;
	}
	cout << cnt;
}