#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	for (getline(cin, str); str != "END"; getline(cin, str)) reverse(str.begin(), str.end()), cout << str << endl;
}