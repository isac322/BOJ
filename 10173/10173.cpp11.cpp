#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	for (getline(cin, s); s != "EOI"; getline(cin, s)) {
		for (auto &c : s) c = tolower(c);
		puts(s.find("nemo") != -1 ? "Found" : "Missing");
	}
}