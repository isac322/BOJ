#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string str;

	while (true) {
		getline(cin, str);
		size_t len = str.length();

		if (len == 1 && str[0] == '0') break;
		printf("%s ", str.c_str());
		while (str.length() != 1) {
			int sum = str[0] - '0';
			for (size_t i = 1; i < str.length(); i++) sum *= str[i] - '0';
			str = to_string(sum);
			printf("%s ", str.c_str());
		}
		puts("");
	}
}