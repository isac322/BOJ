#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string str = "0";
	int n;
	scanf("%d", &n);
	n--;

	while (n--) {
		auto i = 1;
		bool check = true;
		for (; i < str.length(); i++) {
			if (str[i] - 1 != str[i - 1]) {
				check = false;
				break;
			}
		}

		if (check) {
			if (str.back() == '9') {
				if (str.length() == 10) {
					puts("-1");
					return 0;
				}

				char c = '0';
				for (auto &ch : str) ch = c++;

				str.push_back(char(str.length()) + '0');
			}
			else {
				char b = ++str.back();

				char c = '0';
				for (auto &ch : str) ch = c++;

				str.back() = b;
			}
		}
		else {
			str[i - 1]++;

			for (auto j = 0; j < i - 1; j++) str[j] = char(j) + '0';
		}
	}

	reverse(str.begin(), str.end());
	puts(str.c_str());
}