#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	set<string> st;
	cin >> n;
	string name, boolean;
	for (int i = 0; i < n; i++) {
		cin >> name >> boolean;

		if (boolean[0] == 'e') st.insert(name);
		else st.erase(name);
	}

	for (set<string>::reverse_iterator iter = st.rbegin(); iter != st.rend(); iter++) cout << *iter << "\n";
}